#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define pb emplace_back
#define ll long long
#define pii pair<int, int>
#define ld long double

const int INF = 2e9 + 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (auto &c : a) cin >> c;
    vector<int> b(n);
    for (auto &c : b) cin >> c;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += min(a[i], b[i]);
        b[i] -= min(a[i], b[i]);
        ans += min(a[i + 1], b[i]);
        a[i + 1] -= min(a[i + 1], b[i]);
    }
    cout << ans;
    return 0;
}
