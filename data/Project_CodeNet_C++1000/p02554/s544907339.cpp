#include <bits/stdc++.h>

using namespace std;
#define DBG(x)                         \
    (void)(cout << "L" << __LINE__     \
                << ": " << #x << " = " \
                << (x) << '\n')
#define Lower_bound(v, x) distance(v.begin(), lower_bound(v.begin(), v.end(), x))
#define Upper_bound(v, x) distance(v.begin(), upper_bound(v.begin(), v.end(), x))
typedef long long ll;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const long double PI = (acos(-1));
const long double EPS = 0.0000000001;
const int INF = 0x3f3f3f3f;
const int maxn = 1100000;
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
ll cac(ll n)
{
    if (n == 1)
        return 0;
    else
    {
        ll ans = ((power(10, n) - power(9, n) - power(9, n) + power(8, n)) % mod + mod) % mod;
        return ans;
    }
}
void run_case()
{
    ll n;
    cin >> n;
    ll ans = cac(n);
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(12);
    run_case();
    cout.flush();
    return 0;
}