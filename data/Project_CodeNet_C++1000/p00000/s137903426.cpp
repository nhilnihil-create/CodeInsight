#include <iostream>
using namespace std;
int main(void){
    int x,y,z;
    z=0;
    x=0;
    while(1){
        x=x+1;
        while(1){
            z=z+1;
            y=x*z;
            cout<<x<<"x"<<z<<"="<<y<<endl;
            if(z>=9){
                break;
            }
        }
        z=0;
        if(x>=9){
            break;
        }
    }
    
}

