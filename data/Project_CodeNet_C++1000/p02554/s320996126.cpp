#include<cstdio>

typedef long long LL;

const int mod=1e9+7;
const int N=1e6+10;

LL qpow(int a,int b){
    LL res=1;
    LL t=a;
    while(b){
        if(b&1) res=res*t%mod;
        t=t*t%mod;
        b>>=1;
    }
    return res%mod;
}

int main(){
    int n;
    scanf("%d",&n);
    LL ans=qpow(10,n)-2*qpow(9,n)+qpow(8,n);
    ans%=mod;
    if(ans<0) ans+=mod;
    printf("%lld",ans);
    return 0;
}