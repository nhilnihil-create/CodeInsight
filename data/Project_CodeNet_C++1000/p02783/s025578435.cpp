#include<iostream>
#include<math.h>
using namespace std;

int main(){
    double a,b,c,d=0,e=0,m=0;
    cin>>a>>b;
    int z=a;
    while(z>0){
        z-=b;
        m++;
    }
    cout<<m;
    return 0;
}
