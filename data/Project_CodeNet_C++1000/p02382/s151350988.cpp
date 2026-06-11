#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main(){
    int n,x[100]={},y[100]={};
    double max=0.0,a,b=0.0,c=0.0,d=0.0,e,f,g;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int i=0;i<n;i++){
        cin>>y[i];
    }
    for(int i=0;i<n;i++){
        a=abs(x[i]-y[i]);
        b+=a;
        c+=a*a;
        d+=a*a*a;
        if(a>max) max=a;
    }
    e=sqrt(c);
    f=cbrt(d);
    g=max;
    printf("%f\n %f\n %f\n %f\n",b,e,f,g);
    return 0;
}

