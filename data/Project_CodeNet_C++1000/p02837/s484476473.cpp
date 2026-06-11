#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
using ll = long long;

int g[15][15];

int main() {
    int n;
    cin >> n;
    rep(i,n) {
        rep(j,n) {
            g[i][j] = -1;
        }
    }
    rep(i,n) {
        int a;
        cin >> a;
        int x,y;
        rep(j,a) {
            cin >> x >> y;
            g[i][x-1] = y;
        }
    }

    int ans = 0;
    rep(i,1<<n) {
        vector<int> d(n);
        int count = 0;
        rep(j,n) {
            if (i>>j&1) {
                d[j] = 1;
                count++;
            }
        }
        bool t = true;
        rep(j,n) {
            if (d[j]) {
                rep(k,n) {
                    if (g[j][k] == -1) {
                        continue;
                    }
                    if (g[j][k] != d[k]) {
                        t = false;
                    }
                }
            }
        }
        if (t) {
            ans = max(ans, count);
        }

    }

    cout << ans << endl;

    return 0;
}