#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define floop(i, N) for (ll i = 0; i < N; i++)
#define floop1(i, N) for (ll i = 1; i <= N; i++)
#define out(ans) cout << ans << endl
#define in(n) cin >> n

void solve();
ll m, d;

int main()
{
    solve();
}

void solve()
{
    in(m);
    in(d);
    ll ans;
    floop1(i, m)
    {
        floop1(j, d)
        {
            int da[2] = {j / 10, j % 10};
            if (i == da[0] * da[1] && da[0] >= 2 && da[1] >= 2)
            {
                ans++;
            }
        }
    }
    out(ans);
}