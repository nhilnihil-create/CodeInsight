#include <bits/stdc++.h>

using namespace std;
#define DBG(x)                         \
    (void)(cout << "L" << __LINE__     \
                << ": " << #x << " = " \
                << (x) << '\n')

typedef long long ll;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const int maxn = 110000;
const int mod = 1e9 + 7;
ll power(ll a, ll b)
{
    ll ans = 1 % mod;
    while (b > 0)
    {
        if (b & 1)
        {
            ans = ans * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}
int main()
{
    //检查有没有特判0,有没有越界限.
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(12);
    int n;
    cin >> n;
    vector<ll> a(n + 1);
    ll mx = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    int len = 0;
    while (mx)
    {
        mx = mx >>= 1;
        len++;
    }
    vector<ll> cnt0(len + 1), cnt1(len + 1);
    for (int i = 1; i <= n; i++)
    {
        ll cur = a[i];
        int t = 0;
        for (int j = 0; j < len; j++)
        {
            if (cur >> j & 1)
            {
                cnt1[j]++;
            }
            else
            {
                cnt0[j]++;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < len; i++)
    {
        ans = (ans + cnt0[i] * cnt1[i] % mod * ((1ll << i) % mod)) % mod;
    }
    cout << ans << "\n";
    //cout << len << "\n";
    return 0;
}