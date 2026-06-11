#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int m, d; cin >> m >> d;

    int ans = 0;
    for (int i = 2; i <= m; i++) {
        for (int j = 1; j <= d; j++) {
            int d10 = j / 10;
            if (d10 < 2) continue;
            int d1 = j % 10;
            if (d1 < 2) continue;
            if (i == d10 * d1) {
                ans++;
                //printf("%d %d\n", i, j);
            }
        }
    }
   cout << ans << endl;
}