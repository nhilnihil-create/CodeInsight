#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)n; i++)
#define Rep(i, s, n) for (int i = (int)s; i < (int)n; i++)
typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, d;
    cin >> n >> d;
    int x[n][d];
    rep (i, n) {
        rep (j, d) {
            cin >> x[i][j];
        }
    }
    int res = 0;
    rep (i, n - 1) {
        Rep (j, i + 1, n) {
            double dis = 0;
            rep (k, d) {
                dis += pow(x[i][k] - x[j][k], 2);
            }
            dis = sqrt(dis);
            (floor(dis) == dis) ? res++ : 0;
        }
    }
    cout << res << endl;
}