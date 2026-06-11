#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;
const int MOD = 1000000007;
const int MOD2 = 998244353;

ll h[200010];

int main(){
    ll n, k;
    cin >> n >> k;
    ll ans = 0;
    rep(i, n){
        cin >> h[i];
    }
    sort(h, h + n);
    reverse(h, h + n);
    rep(i, n){
        if (i < k) continue;
        else ans += h[i];
    }

    cout << ans << endl;
    return 0;
}
