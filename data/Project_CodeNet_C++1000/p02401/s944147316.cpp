#include <iostream>
using namespace std;

int main(){
    
    
    while(true){
        int a,b;
        char c;
        cin>>a>>c>>b;
        if(c=='?')break;
        if(c=='+')cout<<a+b<<endl;
        if(c=='*')cout<<a*b<<endl;
        if(c=='/')cout<<a/b<<endl;
        if(c=='-')cout<<a-b<<endl;
        
    }
    
    
}

