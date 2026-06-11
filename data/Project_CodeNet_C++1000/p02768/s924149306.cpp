#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int64_t FastPow(int64_t n, int64_t m){
    if(m==0) return 1;
    if(m==1) return n;

    int64_t v=pow(n,m%2),_v=FastPow(n,m/2);

    v*=_v;
    v%=MOD;

    v*=_v;
    v%=MOD;

    return v;
}

int64_t RevS(int64_t n){
    return FastPow(n,MOD-2);
}

int64_t Factori(int64_t n,int64_t m){
    int64_t v=1;
    _rep(i,n,n-m+1){
        v*=i;
        v%=MOD;
    }
    return v;
}

int64_t Comb(int64_t n,int64_t m){
    int64_t v=Factori(n,m);
    v*=RevS(Factori(m,m));
    v%=MOD;
    return v;
}

int main(){
    int64_t n,a,b; cin>>n>>a>>b;

    int64_t ans=FastPow(2,n);

    ans--;
    ans%=MOD;

    ans-=Comb(n,a);
    if(ans<0) ans+=MOD;

    ans-=Comb(n,b);
    if(ans<0) ans+=MOD;

    cout<<ans<<endl;
}