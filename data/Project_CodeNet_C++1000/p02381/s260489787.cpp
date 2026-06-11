#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
int main(void){
    int n,s[1000],sum;
    double a;
    while(1){
        cin>>n;
        if(n==0)break;
        for(int i=0;i<n;i++)cin>>s[i];
        sum=0;
        for(int i=0;i<n;i++)sum+=s[i];
        double avg=double(sum)/n;
        double var=0.0;
        for(int i=0;i<n;i++)var+=pow(s[i]-avg,2.0);
        a=sqrt(var/n);
        printf("%.8f\n",a);
    }
    return 0;
}