#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second

#define pb push_back
#define es erase
#define in insert

#define pii pair<ll, ll>
#define ll long long
#define lb long double

#define ioss                     \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

#define m_p(i, j) make_pair(i, j)
#define mem(a, x) memset(a, x, sizeof(a))
#define endl "\n"
#define all(x) x.begin(), x.end()

const ll mod = 1e9 + 7;
const ll maxn = 6e5 + 7;
ll n, fa[maxn], m, num[maxn];
ll ifind(ll x)
{
    if (x == fa[x])
        return x;
    return fa[x] = ifind(fa[x]);
}
ll cmb(ll x, ll y)
{
    ll fx = ifind(x), fy = ifind(y);
    if (fx != fy) {
        fa[fx] = fy;
        num[fy] += num[fx];
    }
  return 0;
}
int main()
{
    cin >> n >> m;
    for (ll i = 1; i <= n; i++) {
        fa[i] = i;
        num[i] = 1;
    }
    for (ll i = 1; i <= m; i++) {
        ll x, y;
        cin >> x >> y;
        cmb(x, y);
    }
    cout << *max_element(num + 1, num + 1 + n) << endl;
}
