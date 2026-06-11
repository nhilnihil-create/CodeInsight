#include <iostream>
using namespace std;

int divisor(int x,int y){
    return x/y;
}

int main(void){
    int k,a,b;
    cin>>k>>a>>b;
    if(divisor(a-1,k)!=divisor(b,k)) cout<<"OK"<<endl;
    else cout<<"NG"<<endl;
}

