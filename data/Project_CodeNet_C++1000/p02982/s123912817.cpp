#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int n, d, cnt = 0, dist = 0;
    int x[20][20];

    cin >> n >> d;
    rep(i, n) {
        rep(j, d) { cin >> x[i][j]; }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int k = 0; k < d; ++k) {
                dist += pow(abs(x[i][k] - x[j][k]), 2);
            }
            for (int k = 0; k <= dist; ++k) {
                if (k * k == dist) {
                    cnt++;
                }
            }
            dist = 0;
        }
    }
    cout << cnt << endl;
    return 0;
}