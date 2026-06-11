#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int main(){
    int n,S[1000]={};
    while(true){
        int count=0;
        double m,sigma=0,a;
        cin>>n;
        if(n==0) break;
        for(int i=0;i<n;i++){
            cin>>S[i];
            count+=S[i];
        }
        m=1.0*count/n;
        for(int i=0;i<n;i++){
            sigma+=(S[i]-m)*(S[i]-m);
        }
        a=sqrt(sigma/n);
        printf("%f\n",a);
    }
    return 0;
}
