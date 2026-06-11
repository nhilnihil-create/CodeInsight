#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a;
    cin>>a;
    a/=200;
    if(9<=a){
        cout<<1<<endl;
    }else if(8<=a){
        cout<<2<<endl;
    }else if(7<=a){
        cout<<3<<endl;
    }else if(6<=a){
        cout<<4<<endl;
    }else if(5<=a){
        cout<<5<<endl;
    }else if(4<=a){
        cout<<6<<endl;
    }else if(3<=a){
        cout<<7<<endl;
    }else{
        cout<<8<<endl;
    }
}