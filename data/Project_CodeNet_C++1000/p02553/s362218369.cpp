#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;
using P  = pair<int,int>;
const int INF = 1001001001;
const int MOD = 1000000007;
const ll LINF = 1001001001001001001;
int main(){
    vector<ll> a(2), c(2);
    rep(i,2)cin>>a[i];
    rep(i,2)cin>>c[i];
    ll ans = -LINF;
    rep(i,2)rep(j,2)ans=max(ans, a[i]*c[j]);
    cout << ans << endl;
    
    return 0;
}