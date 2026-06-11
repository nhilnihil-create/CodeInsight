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

ll a[200010], f[200010];
int n;

bool isOK(ll x, ll key) {
    ll cost = 0;
    rep(i, n){
        cost += max(a[i] - x/f[i], (ll)0);
    }
    if (cost <= key) return true;
    else return false;
}

ll binary_search(ll key) {
    ll ng = -1;
    ll ok = 1e+18+7;
    while (abs(ok - ng) > 1) {
        ll mid = (ok + ng) / 2;
        if (isOK(mid, key)) ok = mid;
        else ng = mid;
    }
    return ok;
}


int main(){
    ll k;
    cin >> n >> k;
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> f[i];
    sort(a, a+n);
    sort(f, f+n);
    reverse(f, f+n);

    cout << binary_search(k) << endl;

    return 0;
}
