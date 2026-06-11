#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define rep(i, n)   for (int i = 0; i < (n); i++)
#define sz(x)       (int)x.size()
#define eb          emplace_back
#define pb          push_back
#define all(x)      x.begin(), x.end()
#define rall(x)     x.rbegin(), x.rend()
#define fi          first
#define se          second

const int mod(1000000007);

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int x, y;
    cin >> x >> y;

    int t = (x + y) / 3;
    if ((x + y) % 3 || x < t || y < t) {
        cout << 0;
        return 0;
    }

    x -= t, y -= t;

    vector<ll> iv(y + 1);
    iv[1] = 1;
    for (int i = 2; i < sz(iv); i++) {
        iv[i] = (mod - mod / i * iv[mod % i] % mod) % mod;
    }

    ll ret = 1;
    for (int i = 1; i <= y; i++) {
        ret = ret * (x + y - i + 1) % mod * iv[i] % mod;
    }

    cout << ret;

    return 0;
}
