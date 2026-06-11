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
    cin >> n >> k >> s;
    t = 1;
    ans = 0;
    m = 0;
    s = " " + s;
    mp[0] = 1;
    for(int i = n; i > 0; i --)
    {
        m += (s[i] - '0') * t;
        //cout << t<<" ";
        m %= k;
        t *= 10;
        t %= k;
        ans += mp[m];
        ++mp[m];
    }
    if(k == 2 || k == 5)
    {
        ans = 0;
        for(int i = n; i > 0; i --)
        {
            if( (s[i] - '0') % k == 0)
            {
                ans += i;
            }
        }
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    test();
}
