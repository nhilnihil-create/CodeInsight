#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pdd;

#define INF 0x7f7f7f
#define mem(a,b) memset(a , b , sizeof(a))
#define FOR(i, x, n) for(int i = x;i <= n; i++)

// const ll p = 1e9 + 7;
// const ll mod = 998244353;
// const int maxn = 2e5 + 10;
// const double eps = 1e - 6;

int k[100005];

void solve()
{
    string s;
    cin >> s;
    ll len = s.length();
    for(int i = 0;i < len; i++)
    {
        int l = 0, r = 0;
        if(s[i] == 'R')
        {
            while(s[i] == 'R' && i < len)
            {
                l++;
                i++;
            }
            if(l % 2 == 0)
            {
                k[i] += l / 2;
                k[i - 1] += l / 2;
            }
            else
            {
                k[i - 1] += l / 2;
                k[i] += (l - 1) / 2;
                k[i - 1]++;
            }
        }
        if(s[i] == 'L')
        {
            int t = i;
            while(s[i] == 'L' && i < len)
            {
                i++;
                r++;
            }
            if(r % 2 == 0)
            {
                k[t] += r / 2;
                k[t - 1] += r / 2;
            }
            else
            {
                k[t - 1] += r / 2;
                k[t] += (r - 1) / 2 + 1;
            }
            i--;
        }
    }
    for(int i = 0;i < len; i++)
    {
        cout << k[i] << " ";
    }
    cout << endl;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
    //cout.tie(nullptr);
#ifdef FZT_ACM_LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#else
    ios::sync_with_stdio(false);
    int T = 1;
    //cin >> T;
    while(T--)
        solve();
#endif
    return 0;
}