#include<iostream>
#include<math.h>
using namespace std;

int main(){
    long long a,b,c,d=0,e=0,w,x,y,z;
    cin>>a>>b>>c;
    y=c;
    y/=a;
    y*=a;
    if(y>=b){cout<<"OK";}
    else{cout<<"NG";}
    return 0;
}
