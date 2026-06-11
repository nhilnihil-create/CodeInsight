#include<iostream>
#include<math.h>
using namespace std;

int main(){
    double a,b,c,d=0,e=0;
    cin>>a>>b;
    b*=2;
    a-=b;
    if(a<0){cout<<'0'; return 0;}
    else cout<<a;
    return 0;
}
