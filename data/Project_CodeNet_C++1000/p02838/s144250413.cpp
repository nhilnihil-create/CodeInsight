#include <bits/stdc++.h>
using namespace std;
//#include <atcoder/all>
//using namespace atcoder;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define sz(x) int(x.size())
const ll mod = 1000000007;
const ll INF = 1001001001001001000;

int main() {
    int n; cin >> n;
    ll a[n]; rep(i,n) cin >> a[i];
    ll ans = 0;
    ll b = 1;
    rep(i,61) {
        ll cnt = 0;
        rep(j,n) {
            if ((a[j]>>i)&1) cnt++;
        }
        ll p = cnt*(n-cnt)%mod;
        ans = (ans + p*b%mod)%mod;
        b = (b*2)%mod;
    }
    cout << ans << endl;
    return 0;
}
