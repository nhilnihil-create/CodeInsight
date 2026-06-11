#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (int i = a; i < (int)(b); i++)
#define all(v) v.begin(), v.end()
const int MOD = 1e9 + 7;
const int INF = 1e9;
//'A' = 65, 'Z' = 90, 'a' = 97, 'z' = 122

int main() {
    int n, k;
    cin >> n >> k;
    ll h[n];
    rep(i, 0, n) cin >> h[i];
    sort(h, h + n);
    int x = max(0, n - k);
    ll ans = 0;
    rep(i, 0, x) ans += h[i];
    cout << ans << endl;
    return 0;
}
