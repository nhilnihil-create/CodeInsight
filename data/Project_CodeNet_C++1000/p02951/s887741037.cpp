#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a,b,c;
    cin>>a>>b>>c;
    a-=b;
    if(a<=c){
        cout<<c-a<<endl;
    }else{
        cout<<"0"<<endl;
    }
}

