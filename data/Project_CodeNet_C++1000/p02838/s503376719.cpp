#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef pair<int,int> P;
typedef long long ll;
const int INF = 1001001001;
const ll INFL = 1e17;
const int MOD = 1e9+7;


int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n) cin >> a[i];
    ll ans = 0;
    rep(i,60){
        ll x = 0;
        rep(j,n) if(a[j]>>i & 1) ++x;
        ll now = x*(n-x)%MOD;
        rep(j,i) now = now*2%MOD;
        ans += now;
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}