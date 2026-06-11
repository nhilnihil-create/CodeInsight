#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
#define rep(i, n) for (ll (i) = 0; (i) < (n); (i)++)
#define For(i, a, n) for (ll (i) = (a); (i) < (n); (i)++)
#define prl(x) cout << (x) << endl
#define pr(x) cout << (x)
#define all(v) (v).begin(), (v).end()

int main(void){
    ll n,k,ans=0;map<ll,ll> cnt;cin>>n>>k;
    vl a(n),cum(n+1,0),g(n+1,0);rep(i,n)cin>>a[i];
    rep(i,n)cum[i+1]=cum[i]+a[i],g[i+1]=(k+(cum[i + 1]-i-1)%k)%k;
    rep(r,n+1){
        if(r>=k)cnt[g[r-k]]--;
        ans+=cnt[g[r]]++;
    }
    prl(ans);
    return 0;
}