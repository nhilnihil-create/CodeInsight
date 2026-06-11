#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a, b;
    
    cin>>a>>b;
    
    if(a%2 != b%2){
        cout<<"IMPOSSIBLE"<<endl;
    }
    
    else{
        cout<<(a+b)/2<<endl;
        
    }
}