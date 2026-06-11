#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int main(){
    int n;
    double a=0,b=0,d=0,e=0;
    cin>>n;
    double x[n]={};
    double y[n]={};
    double c[n]={};
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    for(int i=0;i<n;i++){
        cin>>y[i];
    }
    for(int i=0;i<n;i++){
            a+=abs(x[i]-y[i]);
            b+=abs((x[i]-y[i])*(x[i]-y[i]));
            e+=abs((x[i]-y[i])*(x[i]-y[i])*(x[i]-y[i]));
    }
    printf("%.6lf\n", a);
    printf("%.6lf\n",sqrt(b));
    printf("%.6lf\n",pow(e,1.0/3.0));
    for(int i=0;i<n;i++){
            c[i]=abs(x[i]-y[i]);
            if(i==0){
                d=c[i];
            }
            else if(c[i]>=d){
                d=c[i];
            }
    }
    printf("%.6lf\n",d);
return 0;
}
