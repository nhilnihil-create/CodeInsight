#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
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

int64_t RevS(int64_t n){
    return FastPow(n,MOD-2);
}

int64_t Factorical(int64_t n, int64_t m){
    int64_t v=1;
    _rep(i,n,n-m+1){
        v*=i;
        v%=MOD;
    }
    return v;
}

int main(){
    int X,Y; cin>>X>>Y;

    int64_t a,b;
    if(2*X-Y>=0 && (2*X-Y)%3==0) a=(2*X-Y)/3;
    else a=-1;
    if(2*Y-X>=0 && (2*Y-X)%3==0) b=(2*Y-X)/3;
    else b=-1;

    if(a<0 || b<0){
        cout<<0<<endl;
        return 0;
    }

    int64_t ans=(Factorical(a+b,a+b-max(a,b))*RevS(Factorical(min(a,b),min(a,b))))%MOD;
    cout<<ans<<endl;
}