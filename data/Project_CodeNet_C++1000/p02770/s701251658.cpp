#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;
const ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, q;
    cin >> k >> q;
    vector<int> d1(k);
    for (auto &c : d1) cin >> c;
    while (q--) {
        int n, x, m;
        cin >> n >> x >> m;
        vector<int> d = d1;
        for (auto &c : d) c %= m;
        int total = n - 1;
        /// a[j] = a[j + 1]
        ll last = x;
        for (int i = 0; i < k; i++) {
            ll cnt = (n - 1) / k + (i < ((n - 1) % k));
            if (d[i] == 0) total -= cnt;
            last += d[i] * cnt;
        }
        /// a[j] > a[j + 1]
        total -= (last / m - x / m);
        cout << total << "\n";
    }
    return 0;
}
