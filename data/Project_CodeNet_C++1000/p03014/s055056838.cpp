#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int MOD = 1000000007;

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> F(h);
    rep(i, h) cin >> F[i];

    //前処理用のはいれちゅを用意
    int L[h][w], R[h][w], U[h][w], D[h][w];

    rep(i, h)
    {
        int cnt = 0;
        rep(j, w)
        {
            cnt++;
            if (F[i][j] == '#')
                cnt = 0;
            L[i][j] = cnt;
        }
    }

    rep(i, h)
    {
        int cnt = 0;
        rep(j, w)
        {
            cnt++;
            if (F[h - i - 1][w - j - 1] == '#')
                cnt = 0;
            R[h - i - 1][w - j - 1] = cnt;
        }
    }

    rep(j, w)
    {
        int cnt = 0;
        rep(i, h)
        {
            cnt++;
            if (F[i][j] == '#')
                cnt = 0;
            U[i][j] = cnt;
        }
    }

    rep(j, w)
    {
        int cnt = 0;
        rep(i, h)
        {
            cnt++;
            if (F[h - i - 1][w - j - 1] == '#')
                cnt = 0;
            D[h - i - 1][w - j - 1] = cnt;
        }
    }

    //前処理終わり

    int ans = 0;
    rep(i, h)
    {
        rep(j, w)
        {
            int res = L[i][j] + R[i][j] + U[i][j] + D[i][j] - 3;
            ans = max(ans, res);
        }
    }

    cout << ans << endl;
}