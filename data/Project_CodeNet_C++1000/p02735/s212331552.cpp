#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;
const ll maxn = 1e6 + 7;
const ll mod = 1e9 + 7;
const int maxx = 1005;
ll q, t, n, m, k, ans, a[maxn], b[maxn], f[maxx][maxx];
priority_queue<ll> pr;
string s, str;
char ss[maxx][maxx];
map<ll, ll> mp;
void sol()
{
    cin >> n;
    ll mx = 1e16;
    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
    }
    for(int i = n - 1; i >= 0; i--)
    {
        for(int j = i; j >= 0; j --)
        {
            if(i == n - 1)f[i][j] = (j == 0 ? a[i] : 0);
            else
                f[i][j] = min(a[i] + f[i+1][a[i] > 100 ? j + 1 : j], j > 0 ? f[i+1][j-1] : mx);
        }
    }
    cout << f[0][0];
}
void test()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
            {
                cin >> ss[i][j];
            }
    }
    for(int i = 1; i <= n; i ++)
    {
        for(int j = 1; j <= m; j ++)
        {
            ll up, lf;
            if(ss[i][j] == '.')
            {
                if(i > 1)
                    up = f[i-1][j];
                else
                    up = 1e9;
                if(j > 1)
                    lf = f[i][j-1];
                else
                    lf = 1e9;
                f[i][j] = min(up, lf);
                if(i == 1 && j == 1)f[i][j] = 0;
            }
            else
            {
                if(i > 1)
                {
                    up = f[i-1][j];
                    if(ss[i-1][j] == '.')
                        up += 1;
                }
                else
                    up = 1e9;
                if(j > 1)
                {
                    lf = f[i][j-1];
                    if(ss[i][j-1] == '.')
                        lf += 1;
                }
                else
                    lf = 1e9;
                f[i][j] = min(up, lf);
                if(i == 1 && j == 1)f[i][j] = 1;
            }
        }

    }
    cout << f[n][m];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    test();
}
