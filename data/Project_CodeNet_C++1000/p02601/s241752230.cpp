#include<bits/stdc++.h>
using namespace std;
int main(){int k,a,b,c,ta,tb,tc,i,ok=0,t1,t2,t3;
int m[10];
m[0]=1;
for(i=1;i<10;i++)m[i]=2*m[i-1];
cin>>a>>b>>c>>k;
for(ta=0;ta<=k;ta++){
    for(tb=0;ta+tb<=k;tb++){
        tc=k-ta-tb;
        t1=a,t2=b,t3=c;
        t1*=m[ta];
        t2*=m[tb];
        t3*=m[tc];
        if(t3>t2&&t2>t1)ok=1;
    }
}
if(ok){cout<<"Yes";}
else{cout<<"No";}
    return 0;}