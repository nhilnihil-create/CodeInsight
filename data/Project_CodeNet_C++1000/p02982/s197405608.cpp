#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

double check_dist(int *x, int *y, int d) {
    int root;
    double v = 0;
    rep(i, d) v += (x[i] - y[i]) * (x[i] - y[i]);
    root = int(sqrt(v));
    // cout << "result:" << (root * root) == v << endl;
    return root * root == v;
}

int main() {
    int n, d, ans = 0;
    cin >> n >> d;
    int x[n][d];

    rep(i, n) rep(j, d) cin >> x[i][j];
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(check_dist(x[i], x[j], d)) {
                // cout << "i:" << i << ",j:" << j << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
