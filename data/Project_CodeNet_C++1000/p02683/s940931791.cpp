#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    const int max = 10000000;
    int n, m, x, ans = max;
    cin >> n >> m >> x;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> c(n), alg(m);
    rep(i, n) {
        cin >> c[i];
        rep(j, m) { cin >> a[i][j]; }
    }

    for(int bit = 1; bit < (1 << n); bit++) {
        int money = 0;
        vector<int> alg(m);
        rep(i, n) {
            if(bit & (1 << i)) {
                rep(j, m) alg[j] += a[i][j];
                money += c[i];
            }
        }
        bool flag = true;
        rep(i, m) {
            if(alg[i] < x) {
                flag = false;
                break;
            }
        }
        if(flag) {
            ans = min(ans, money);
        }
    }
    if(ans == max) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}
