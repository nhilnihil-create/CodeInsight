#include <iostream>
using namespace std;
int main(void){
    int a,b;
    cin>>a>>b;
    a+=b;
    if(a%2==0){
        cout<<a/2<<endl;
    }else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}