#include <bits/stdc++.h>
#define int long long

#define rng(i, l, r) for (size_t i = (l); i < (r); ++i)
#define rep(i, n) rng(i, 0, n)
#define gnr(i, l, r) for (size_t i = (r)-1; i >= (l); i--)
#define per(i, b) gnr(i, 0, b)
#define ALL(obj) (obj).begin(), (obj).end()    //1,2,3,...
#define rALL(obj) (obj).rbegin(), (obj).rend() //...,3,2,1

using namespace std;

const int INF = 1e18;

int MIN(int a, int b)
{
    return (a > b) ? b : a;
}



void solve()
{

    // remove the bottom 3 lines when you submit this code.
    std::ifstream in("sample.txt");
    std::cin.rdbuf(in.rdbuf());

    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W, K; cin >> H >> W >> K;

    vector<string> c(H); rep(h, H) cin>> c[h];

    int ans = 0;
    for (int h = 0; h < (1<<H); h++) {
        for (int w = 0; w < (1<<W); w++) {

            int cnt = 0;

            for (int hi = 0; hi < H; hi++) {
                for (int wi = 0; wi < W; wi++) {

                    if ((h >> hi) & 1) continue;
                    if ((w >> wi) & 1) continue;

                    if (c[hi][wi] == '#') cnt++;
                }
            }

            if (cnt == K) ans++;

        }
    }

    cout << ans << endl;


}

signed main()
{
    solve();
    return 0;
}
