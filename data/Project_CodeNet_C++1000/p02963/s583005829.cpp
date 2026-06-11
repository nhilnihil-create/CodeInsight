#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s;
int main(){
    scanf("%lld",&s);
    ll x,y,a,b;
    ll k=sqrt(s);
    ll m=k*k;
    if(m==s){
        printf("%lld %lld %lld %lld %lld %lld",0,0,0,k,k,0);
    }
    else {
        if(m+k>s)y=k+1,a=k-1;
        if(m+k<=s)y=k+1,a=k;
        b=s-a*y;
        x=a+1;
        printf("%lld %lld %lld %lld %lld %lld",a,0,0,b,x,y);
    }
    
    return 0;
}
