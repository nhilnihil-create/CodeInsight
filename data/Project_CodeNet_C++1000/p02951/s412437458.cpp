#include<iostream>
#include<math.h>
using namespace std;

int main(){
    long long a,b,c=0,d,x=0,y=0,z=0;
    cin>>a>>b>>c;
    z=b+c;
    if(a>=z){cout<<0; return 0;}
    if(a<z){z-=a; cout<<z;}
    return 0;
}
