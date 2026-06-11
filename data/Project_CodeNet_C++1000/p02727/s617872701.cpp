#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;

    vector<int> p(a), q(b), r(c);
    rep(i, a) cin >> p[i];
    rep(i, b) cin >> q[i];
    rep(i, c) cin >> r[i];

    sort(p.begin(), p.end(), greater<int>());
    sort(q.begin(), q.end(), greater<int>());
    sort(r.begin(), r.end(), greater<int>());

    int z = 0;
    while (true)
    {
        if (x == 0 && y == 0)
            break;
        if (x == 0)
        {
            if (q[y - 1] < r[z])
            {
                --y;
                ++z;
                if (z == c)
                    break;
                continue;
            }
        }
        else if (y == 0)
        {
            if (p[x - 1] < r[z])
            {
                --x;
                ++z;
                if (z == c)
                    break;
                continue;
            }
        }
        else
        {
            if (p[x - 1] < q[y - 1])
            {
                if (p[x - 1] < r[z])
                {
                    --x;
                    ++z;
                    if (z == c)
                        break;
                    continue;
                }
            }
            else
            {
                if (q[y - 1] < r[z])
                {
                    --y;
                    ++z;
                    if (z == c)
                        break;
                    continue;
                }
            }
        }

        break;
    }

    ll ans = 0;
    rep(i, x) ans += p[i];
    rep(i, y) ans += q[i];
    rep(i, z) ans += r[i];

    cout << ans << endl;
}