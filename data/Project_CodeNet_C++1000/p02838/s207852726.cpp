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
        //mx = max(mx, a[i]);
    }
    ll ans = 0;
    for (int bit = 0; bit < 60; bit++)
    {
        ll cnt0 = 0, cnt1 = 0;
        for (int i = 1; i <= n; i++)
        {
            ll cur = a[i];
            if ((cur >> bit) & 1)
            {
                cnt1++;
            }
            else
            {
                cnt0++;
            }
        }
        ans = (ans + cnt0 % mod * cnt1 % mod * ((1ll << bit) % mod) % mod) % mod;
    }
    cout << ans << "\n";
    //cout << len << "\n";
    return 0;
}