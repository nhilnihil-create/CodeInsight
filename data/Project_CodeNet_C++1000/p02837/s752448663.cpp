#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <queue>
#include <set>
#include <cassert>

#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
typedef long long int ll;
const ll INF = 1000000000000000000;
const double PI = acos(-1);

int main()
{
    int n;
    int a[15];
    int x[15][14];
    int y[15][14];
    cin >> n;
    rep(i, n) {
        cin >> a[i];
        rep(j, a[i]) {
            cin >> x[i][j] >> y[i][j];
            x[i][j]--;
        }
    }

    int ans = 0;
    for (int bit = 0; bit < (1 << n); bit++) {
        bool is_ok = true;
        vector<int> honesty(n, -1);
        rep(i, n) {
            if (bit & (1 << i)) {
                rep(j, a[i]) {
                    if (honesty[i] == 0 || (x[i][j] == i && y[i][j] == 0)
                        || (honesty[x[i][j]] == 1 && y[i][j] == 0)
                        || (honesty[x[i][j]] == 0 && y[i][j] == 1)) {
                        is_ok = false;
                    }
                    if (y[i][j] == 1 && !(bit & (1 << x[i][j]))) {
                        is_ok = false;
                    }
                    if (y[i][j] == 0 && (bit & (1 << x[i][j]))) {
                        is_ok = false;
                    }
                    honesty[i] = 1;
                    honesty[x[i][j]] = y[i][j];
                }
            }
        }
        if (is_ok) {
            int cnt = 0;
            rep(i, n) {
                if (bit & (1 << i)) cnt++;
            }
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
}