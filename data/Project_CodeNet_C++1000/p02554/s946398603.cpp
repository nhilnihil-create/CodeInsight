#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long p(long long a,long long b){
    int res=1;
    while(b>0) {
        if(b&1) res=res*a %mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
int main() {
    long long n;
    scanf("%lld",&n);
    long long ans=p(10,n)-2*p(9,n)+p(8,n); 
	ans%=mod; 
	ans=(ans+mod)%mod;
    printf("%lld",ans);
}