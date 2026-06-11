#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i,n) for(int (i)=0; (i) < (n); (i)++)

int main()
{
    ll H, W, K; cin >> H >> W >> K;
    vector<vector<ll>> c(H, vector<ll>(W, 0));
    rep(i,H) {
        string s; cin >> s;
        rep(j,W) {
            if (s[j] == '#') {
                c[i][j] = 1;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < (1<<H); ++i) {
        vector<vector<ll>> tmp(H, vector<ll>(W, 0));
        tmp = c;
#if 0
        cout << "[1]" << endl;
        rep(ii,H) {
            rep(iii, W) {
                if (tmp[ii][iii] == 1) cout << 1;
                else cout << 0;
            }
            cout << endl;
        }
#endif
        for (int j = 0; j < H; ++j) {
            if ((i >> j) & 0x01) {
                for (int k = 0; k < W; ++k) tmp[j][k] = 0;
            }
        }
        for (int k = 0; k < (1<<W); ++k) {
            vector<vector<ll>> tmp2(H, vector<ll>(W, 0));
            tmp2 = tmp;
            for (int kk = 0; kk < W; ++kk) {
                if ((k >> kk) & 0x01) {
                    for (int kkk = 0; kkk < H; ++kkk) tmp2[kkk][kk] = 0;
                }
            }
#if 0
            cout << "[2]" << endl;
            rep(ii,H) {
                rep(iii, W) {
                    if (tmp2[ii][iii] == 1) cout << 1;
                    else cout << 0;
                }
                cout << endl;
            }
#endif
            ll cnt = 0;
            rep(ii,H) {
                rep(iii, W) {
                    if (tmp2[ii][iii] == 1) cnt++;
                }
            }
            if (cnt == K) ans++;
        }
    }
    cout << ans << endl;

    




}
