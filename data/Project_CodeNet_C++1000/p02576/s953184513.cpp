#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using st = string;
using P = pair<int, int>;
#define mrep(i, m, n) for(int i = m; i < n; i++)
#define rep(i, n) mrep(i, 0, n)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)

int main() {
    int n, x, t;
    cin >> n >> x >> t;
    int times = (n + x - 1) / x;
    int ans = t * times;
    cout << ans << endl;
}