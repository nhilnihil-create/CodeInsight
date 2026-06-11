#include<iostream>
#include<math.h>
using namespace std;

int main(){
    double a,b,c,d=0,e=0,z=0;
    cin>>b;
    a=b;
    a/=1000;
    z=ceil(a);
    z*=1000;
    z-=b;
    cout<<z;
}
