#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;

int main() {

    ll n; cin >> n;
    vector<ll> a(n + 1);
    for (int i = 0; i < n + 1; ++i) {
        cin >> a[i];
    }

    // 各深さで取り得る頂点数の範囲
    vector<ll> l(n + 1, 0);
    vector<ll> r(n + 1, 0);

    l[n] = r[n] = a[n];

    // 深さ(i + 1)での範囲が(l[i + 1], r[i + 1])の時、深さiでは葉でない頂点数はその半分以上あればよい
    for (int i = n - 1; i >= 0; --i) {
        l[i] = a[i] + (l[i + 1] + 1) / 2; // 最小値
        r[i] = a[i] + r[i + 1]; // 最大値
    }

    if (l[0] > 1) {
        cout << -1 << endl;
        return 0;
    }

    ll ans = 0;
    // 頂点から見ていく
    ll cur = 1;
    for (int i = 0; i < n + 1; ++i) {
        ans += cur;
        cur -= a[i]; // 葉の数を引く
        cur = min(cur * 2, r[i + 1]);
    }

    cout << ans << endl;
}