#include<iostream>
#include<stdio.h>
#include<cmath>
 
using namespace std;
int main () {
    int n;
    double x[99],y[99],p1=0,p1check=0,p2=0,p3=0,pinfty=0;
    cin >> n;
    for(int i=0;n>i;i++) cin >> x[i];
    for(int i=0;n>i;i++) cin >> y[i];
    for(int i=0;n>i;i++){
        p1+=abs(x[i]-y[i]);
        p2+=(x[i]-y[i])*(x[i]-y[i]);
        p3+=abs((x[i]-y[i])*(x[i]-y[i])*(x[i]-y[i]));
        if(abs(x[i]-y[i])>pinfty) pinfty=abs(x[i]-y[i]);
    }
    printf("%.6f\n",p1);
    printf("%.6f\n",sqrt(p2));
    printf("%.6f\n",cbrt(p3));
    printf("%.6f\n",pinfty);
}
