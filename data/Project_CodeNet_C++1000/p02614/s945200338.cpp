#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using ll = long long;
using vec = vector<ll>;
using vec2 = vector<vector<ll>>;
ll inf = pow(2, 62);

int main()
{
    ll h, w, k;
    cin >> h >> w >> k;
    vector<string> masu(h);
    rep(i, h)
    {
        cin >> masu[i];
    }
    ll ans = 0;
    rep(is, 1 << h)
    {
        rep(js, 1 << w)
        {
            ll cnt = 0;
            rep(i, h)
            {
                rep(j, w)
                {
                    if (is >> i & 1)
                    {
                        continue;
                    }
                    if (js >> j & 1)
                    {
                        continue;
                    }
                    if (masu[i][j] == '#')
                    {
                        cnt++;
                    }
                }
            }
            if (cnt == k)
            {
                ans++;
            }
        }
    }
    cout << ans << endl;
}