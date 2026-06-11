#include <bits/stdc++.h>
using namespace std;
using lint = long long;
using P = pair<int, int>;
using vec = vector<int>;
using mat = vector<vector<int>>;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define endl "\n"

constexpr int MOD = 1000000007;
const int INF = 1 << 30;

int main() {
    int n;
    cin >> n;
    vec a(n);
    rep(i, n) cin >> a[i];

    sort(all(a));

    int x1 = a[n-1], x2 = a[0];

    vector<P> history;

    rep(i, n) {
        if (a[i] > 0 && i > 0 && i < n-1) {
            int y = a[i];
            history.push_back({x2, y});
            x2 -= y;
        }
    }

    rep(i, n) {
        if (a[i] <= 0 && i > 0 && i < n-1) {
            int y = a[i];
            history.push_back({x1, y});
            x1 += abs(y);
        }
    }

    history.push_back({x1, x2});
    x1 -= x2;

    cout << x1 << endl;
    rep(i, n-1) {
        printf("%d %d\n", history[i].first, history[i].second);
    }

    return 0;
}