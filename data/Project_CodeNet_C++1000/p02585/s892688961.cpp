#include <bits/stdc++.h>
//#include <atcoder/all>
#define rep(i,n) for (int i=0;i<(n);i++)
using ll = long long;
using namespace std;
//using namespace atcoder;

int main() {
    int n,k;cin>>n>>k;
    int p[n],c[n];
    rep(i,n) cin>>p[i],p[i]--;
    rep(i,n) cin>>c[i];
    ll ans=-1e9;
    rep(i,n) {
        int cu=i,a=0;
        ll sm=0;
        while (1) {
            cu=p[cu];
            a+=1;
            sm+=c[cu];
            if (cu==i) break;
        }
        sm=max(0LL,sm);
        ll s=0;
        rep(j,a) {
            cu=p[cu];
            s+=c[cu];
            ans=max(ans,sm*((k-j-1)/a)+s);
            if (j+1==k||cu==i) break;
        }
    }
    cout<<ans<<endl;
    return 0;
}