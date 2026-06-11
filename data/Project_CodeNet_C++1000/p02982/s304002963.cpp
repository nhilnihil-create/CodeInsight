#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, d;
    cin >> n >>d;
    int x[n][d];
    rep(i, n) {
        rep(j, d) cin >> x[i][j];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double dist = 0;
            for (int k = 0; k < d; k++) {
                dist += pow(x[i][k] - x[j][k], 2);
            }
            dist = sqrt(dist);
            if(floor(dist) == dist) ans++;
        }
    }

    cout << ans;
}
