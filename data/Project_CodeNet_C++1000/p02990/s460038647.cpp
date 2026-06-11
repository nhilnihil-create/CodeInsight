#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int64_t i=ini;i<n;i++)
#define _rep(i,ini,n) for(int64_t i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int64_t FastPow(int64_t n, int64_t m){
    if(m==0) return 1;
    if(m==1) return n;

    int64_t v=FastPow(n,m/2);
    v*=v;
    v%=MOD;
    if(m%2){
        v*=n;
        v%=MOD;
    }
    return v;
}

int64_t RevS(int64_t n,int64_t m){
    return FastPow(n,m-2);
}

int64_t Factr(int64_t n,int64_t m){
    int64_t v=1;
    rep(i,n-m+1,n+1){
        v*=i;
        v%=MOD;
    }
    return v;
}

int64_t Comb(int64_t n,int64_t m){
    //m=min(m,n-m);
    return (Factr(n,m)*RevS(Factr(m,m),MOD))%MOD;
}

int main(){
    int N,K; cin>>N>>K;

    rep(i,1,K+1){
        int64_t ans=Comb(K-1,i-1);
        ans*=Comb(N-K+1,i);
        ans%=MOD;
        cout<<ans<<endl;
    }
}