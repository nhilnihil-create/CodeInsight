#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pll = pair<ll, ll>;

#define all(a) a.begin(), a.end()
#define pb push_back
#define mp make_pair


template <typename T>
using vv = vector<vector<T>>;

void solve() {
    int n; cin >> n;
    int k; cin >> k;
    vi a(n);
    for (auto &i : a) cin >> i, i *= 2;
    ll l = 0, r = 2e9 + 5;
    while (r - l > 1) {
        ll m = (l + r) / 2;
        ll sum = 0;
        for (auto &z : a) sum += max(0LL, (z + m - 1) / m - 1);
        if (sum > k) l = m;
        else r = m;
    }
    cout << (r + 1) / 2;
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
}
