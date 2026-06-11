#include <bits/stdc++.h>
using namespace std;

long long gcd(long long c, long long d){
    if(c%d==0){
        return d;
    }else{
        return gcd(d, c%d);
    }
}

long long lcm(long long c, long long d){
    return c*d/gcd(c, d);
}

int main(void){
    long long a,b,c,d;
    cin>>a>>b>>c>>d;
    long long asum, bsum, cm, dm, cdm;
    cm=(a-1)/c;
    dm=(a-1)/d;
    cdm=(a-1)/lcm(c,d);
    asum=(a-1)-cm-dm+cdm;
    
    cm=b/c;
    dm=b/d;
    cdm=b/lcm(c,d);
    bsum=b-cm-dm+cdm;
    
    cout<<bsum-asum<<endl;
    return 0;
}