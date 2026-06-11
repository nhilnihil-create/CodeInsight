#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define ld long double

const int INF = 2e9 + 1;
const ll INFLL = 1e18 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<ll> cnt(n + 1);
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }
    ll ans = 0;
    for (auto &c : cnt) ans += c * (c - 1) / 2;
    for (auto &c : a) {
        ans -= cnt[c] * (cnt[c] - 1) / 2;
        cnt[c]--;
        ans += cnt[c] * (cnt[c] - 1) / 2;
        cout << ans << "\n";
        ans -= cnt[c] * (cnt[c] - 1) / 2;
        cnt[c]++;
        ans += cnt[c] * (cnt[c] - 1) / 2;
    }
    return 0;
}
