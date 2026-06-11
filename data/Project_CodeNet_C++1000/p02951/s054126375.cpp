#include<iostream>
using namespace std;
int main(){
    int a,b,c,x;
    cin>>a>>b>>c;
    x=a-b;
    if(c<=x){
        cout<<0;
    }
    else{
        cout<<c-x;
    }
}
