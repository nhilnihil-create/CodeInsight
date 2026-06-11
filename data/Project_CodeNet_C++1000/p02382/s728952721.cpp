#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
int main(){
    int i,n;
    cin>>n;
    int x[n],y[n];
    for(i=0;i<n;i++)cin>>x[i]; 
    for(i=0;i<n;i++)cin>>y[i];
    double manhattan=0,euclidean2=0,euclidean3=0,chebyshev=0;
    for(i=0;i<n;i++){
        manhattan+=abs(x[i]-y[i]);
        if(chebyshev<abs(x[i]-y[i]))chebyshev=abs(x[i]-y[i]);
    }
    for(i=0;i<n;i++)euclidean2+=pow(abs(x[i]-y[i]),2);
    for(i=0;i<n;i++)euclidean3+=pow(abs(x[i]-y[i]),3);
    printf("%.5f\n%.5f\n%.5f\n%.5f\n",manhattan,sqrt(euclidean2),cbrt(euclidean3),chebyshev);
    return 0;
}
