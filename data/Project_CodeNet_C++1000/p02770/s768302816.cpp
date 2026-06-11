#include <bits/stdc++.h>
using ll = long long;
using namespace std;

constexpr int inf = 1e9;
constexpr ll linf = 1e18;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int k, q; cin >> k >> q;
    vector<ll> d(k);
    for (int i = 0; i < k; i++) cin >> d[i];

    while (q--) {
        ll n, x, m; cin >> n >> x >> m;

        vector<ll> s(k + 1, 0);
        for (int i = 0; i < k; i++) s[i + 1] = s[i] + (d[i] % m ? d[i] % m : m);

        ll sum = x % m;
        sum += s[k] * ((n - 2) / k);
        sum += s[(n - 2) % k + 1];

        ll ans = n - sum / m - 1;
        cout << ans << endl;
    }
    return 0;
}