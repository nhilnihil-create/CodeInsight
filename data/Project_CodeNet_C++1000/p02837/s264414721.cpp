#include <bits/stdc++.h>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main()
{
    int n,a;
    int x1,y1,xy[16][16];

    rep(i, 16)
        rep(j, 16)
            xy[i][j] = -1;

    cin >> n;
    rep(i, n) {
        cin >> a;
        rep(j, a) {
            cin >> x1 >> y1;
            xy[i][x1 - 1] = y1;
        }
    }

    int ans = 0;
    rep(bit, (1 << n)) {
        vector<int> nn(n);
        int bitcnt = 0;
        rep(i, n)
            if ((bit >> i) & 1) {
                nn[i] = 1;
                ++bitcnt;
            }

        bool ok = true;
        rep(i, n) {
            if (nn[i] == 1) {
                rep(j, n) {
                    if (xy[i][j] == -1)
                        continue;
                    if (xy[i][j] != nn[j])
                        ok = false;
                }
            }
        }
        if (ok == true)
            ans = max(ans,bitcnt);
    }

    cout << ans << endl;
}