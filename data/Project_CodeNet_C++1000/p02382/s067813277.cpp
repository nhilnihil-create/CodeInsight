#include <bits/stdc++.h>
using namespace std;
 
int main(){
    double a[100]={0.0},b[100]={0.0},c[100]={0.0},d1=0.0,d2=0.0,d3=0.0,d0=0.0;
    int e;
    cin>>e;
    for(int i=0;i<e;i++){
        cin>>a[i];
    }
    for(int i=0;i<e;i++){
        cin>>b[i];
    }
    for(int i=0;i<e;i++){
        c[i]=a[i]-b[i];
        if(c[i]<0)c[i]=c[i]*(-1);
    }
    for(int i=0;i<e;i++){
        d1+=c[i];
    }
    for(int i=0;i<e;i++){
        d2+=c[i]*c[i];
    }
    for(int i=0;i<e;i++){
        d3+=pow(c[i],3);
    }
    for(int i=0;i<e;i++){
        if(d0<c[i])d0=c[i];
    }
    d2=sqrt(d2);
    d3=pow(d3,1.0/3.0);
    cout <<setprecision(15)<<d1<<"\n"<<d2<<"\n"<<d3<<"\n"<<d0<<endl;
}