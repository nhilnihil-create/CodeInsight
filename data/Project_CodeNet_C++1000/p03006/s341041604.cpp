#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

signed main() {
    int N;
    cin >> N;
    vector<int> x(N), y(N);
    rep(i, N) cin >> x[i] >> y[i];
    
    if (N == 1 || N == 2) {
        cout << 1 << endl;
        return 0;
    }
    
    int ans = 1000000000;
    rep(i, N) rep(j, N) {
        if (i == j) continue;
        int p = x[i] - x[j];
        int q = y[i] - y[j];
        int cost = N;
        rep(k, N) {
            int X = x[k] - p;
            int Y = y[k] - q;
            rep(l, N) if (x[l] == X && y[l] == Y) --cost;
        }
        ans = min(ans, cost);
    }
    
    cout << ans << endl;
    return 0;
}
