#include <bits/stdc++.h>
#include <string>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

int main()
{
    int n,ans;

    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    rep(i, n) {
        rep(j, n) g[i][j] = -1;
        int a,x,y;
        cin >> a;
        rep(j, a) {
            cin >> x >> y;
            g[i][--x] = y;
        }
    }

    ans = 0;
    for (int bit = 0; bit < (1 << n); ++bit) {
        vector<int> d(n);
        int bitcount = 0;
        rep(i, n) {
            if ((bit >> i) & 1) {
                d[i] = 1;
                ++bitcount;
            }
        }
        bool ok = true;
        rep(i,n) {
            if (d[i]) {
                rep(j, n) {
                    if (g[i][j] == -1)
                        continue;
                    if (g[i][j] != d[j])
                        ok = false;
                }
            }
        }
        if (ok)
            ans = max(ans, bitcount);
    }

    std::cout << ans << endl;

    return 0;
}

