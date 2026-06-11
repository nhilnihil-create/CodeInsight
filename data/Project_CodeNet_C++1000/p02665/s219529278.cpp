#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define F first
#define S second
#define pb push_back
#define eb emplace_back
#define PI 3.14159265359
#define sz(c) (int)c.size()
#define len(c) (int)c.length()
#define hcf(a, b) __gcd(a, b)
#define all(c) c.begin(), c.end()
#define vint vector<int>
#define vll vector<ll>
#define vpint vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define fr(it, a, b) \
    for (int it = (a); it < (b); it++)
#define tr(con, it) \
    for (auto it = con.begin(); it != con.end(); it++)
#define present(con, ele) (con.find(ele) != con.end())
#define cpresent(con, ele) (find(all(con), ele) != con.end())
#define maximum(a, b, c) (a > b ? (a > c ? a : c) : (b > c ? b : c))
#define minimum(a, b, c) (a < b ? (a < c ? a : c) : (b < c ? b : c))
typedef long long ll;
typedef long double lf;
typedef unsigned long long lu;
const ll mod = 1e9 + 7, m = 1e18;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, ans = 1;
    cin >> n;
    n++;
    vll a(n + 2), mx(n + 2), sum(n + 2);
    fr(i, 1, n + 1)
    {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 1; i--)
    {
        sum[i] = sum[i + 1] + a[i + 1];
    }
    mx[1] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (mx[i] < a[i])
        {
            ans = -1;
            break;
        }
        else
        {
            mx[i + 1] = min((mx[i] - a[i]) * 2, m);
        }
        ans += min(mx[i + 1], sum[i]);
    }
    cout << ans << endl;
    return 0;
}