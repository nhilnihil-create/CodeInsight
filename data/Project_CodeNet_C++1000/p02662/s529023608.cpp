#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
const int MAXN = 10 + 1e6;
const ll oo = 1 + 1e18;
const ll mod = 998244353;

int n, s, a[MAXN];
ll f[MAXN];

int main()
{
    #define TASK "ABC"
    #ifndef ONLINE_JUDGE
    freopen(TASK".inp","r",stdin);
    freopen(TASK".out","w",stdout);
    #endif ONLINE_JUDGE
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> s;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    f[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = s; j >= 0; j--)
        {
            f[j] *= 2;
            f[j] %= mod;
            if (j >= a[i])
            {
                f[j] += f[j - a[i]];
                f[j] %= mod;
            }
        }
    }

    cout << f[s];

    return 0;
}


















































































