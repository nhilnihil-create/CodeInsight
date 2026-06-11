#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    int a, b, c, k;
    cin >> a >> b >> c >> k;
    int cnt = 0;
    while (a >= b) {
        b *= 2;
        cnt++;
    }
    while (b >= c) {
        c *= 2;
        cnt++;
    }
    cout << (cnt <= k ? "Yes" : "No") << endl;
    return 0;
}