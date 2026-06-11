#include<iostream>
#include<math.h>
using namespace std;

int main(){
    double a,b,c,d=0,e=0;
    cin>>a>>b;
    if(a==1 && b==2 || a==2 && b==1){cout<<3;}
    if(a==1 && b==3 || a==3 && b==1){cout<<2;}
    if(a==2 && b==3 || a==3 && b==2){cout<<1;}
    return 0;
}
