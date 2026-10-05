#include <iostream>


class wire{
    private:
        bool state;
    public:
        wire(){
            this->state = 0;
        }
        wire(bool state){
            this->state = state;
        }
        void toggle(){
            state = !state;
        }
        void set_state(bool state){
            this->state = state;
        }
        bool get_state() const{
            return state; 
        }
};

class gate{
    private:

    public:
        virtual void eval() = 0;
        virtual ~gate() = default;

};

class Notgate:public gate{
    private:
        wire* input;
        wire* output;
    public:
        Notgate(wire* input, wire* output){
            this->input = input;
            this->output = output;
        }

        void eval() override{
            output->set_state(!(input->get_state()));
        }
};
class Andgate:public gate{
    private:
        wire* input_1;
        wire* input_2;
        wire* output;
    public:
        Andgate(wire* input_1, wire* input_2 ,wire* output){
            this->input_1 = input_1;
            this->input_2 = input_2;
            this->output = output;
        }

        void eval() override{
            bool res = input_1->get_state() && input_2->get_state();
            output->set_state(res);
        }
};


int main(int argc, char* argv[]){

    wire a(1);
    wire b(1);
    wire out_1;
    wire out_2;
    Andgate ag(&a,&b,&out_1);
    Notgate n(&out_1,&out_2);
    ag.eval();
    n.eval();
    std::cout << out_2.get_state();



    
    

}
