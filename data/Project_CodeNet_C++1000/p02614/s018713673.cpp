#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pll = pair<ll, ll>;

#define rep(i, n) for (ll i = 0, xxx_rep_end = (n); i < xxx_rep_end; ++i)
#define all(x) (x).begin(), (x).end()

template <class T1, class T2>
inline void chmax(T1 &a, const T2 &b)
{
    if (a < b)
    {
        a = b;
    }
}
template <class T1, class T2>
inline void chmin(T1 &a, const T2 &b)
{
    if (a > b)
    {
        a = b;
    }
}

constexpr ll INF = 0x3f3f3f3f3f3f3f3fLL;

char v[6][6];
int main()
{
    ll H, W, K;
    cin >> H >> W >> K;

    rep(i, H)
    {
        string c;
        cin >> c;
        rep(j, W)
        {
            v[i][j] = c[j];
        }
    }
    ll ans = 0;

    for (ll i = 0, end_i = 1 << H; i < end_i; ++i)
    {
        for (ll j = 0, end_j = 1 << W; j < end_j; ++j)
        {
            ll black = 0;
            rep(x, H)
            {
                rep(y, W)
                {
                    // (x, y)が赤で塗りつぶされていないか
                    if ((((i >> x) & 1) == 0) && (((j >> y) & 1) == 0))
                    {
                        if (v[x][y] == '#')
                        {
                            ++black;
                        }
                    }
                }
            }
            if (black == K)
            {
                ++ans;
            }
        }
    }
    cout << ans << endl;
}