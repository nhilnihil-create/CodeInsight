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

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("io\\in.txt", "r", stdin);
    freopen("io\\out.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    vi f(1001);
    rep(i, n) {
        int x;
        cin >> x;
        f[x]++;
    }

    ll cnt = 0;
    for (int i = 1; i <= 1000; i++) {
        ll cur = f[i];
        f[i]--;

        for (int j = i / 2 + 1; j <= i; j++) {
            ll cur2 = cur * f[j];
            if (i == j) cur2 /= 2;
            f[j]--;

            for (int k = i - j + 1; k <= j; k++) {
                ll cur3 = cur2 * f[k];
                if (i == k) cur3 /= 3;
                else if (j == k) cur3 /= 2;
                cnt += cur3;
            }

            f[j]++;
        }

        f[i]++;
    }
    
    cout << cnt;

    return 0;
}
