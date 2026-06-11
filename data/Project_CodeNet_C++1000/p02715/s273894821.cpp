#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;
const ll maxn = 1e6 + 7;
const ll mod = 1e9 + 7;
const ll mod1 = 123456789;
const int maxx = 1005;
ll q, t, n, m, T, k, ans, a[maxn], b[maxn], c[maxn], f[maxx][maxx];
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

char ch;
string gach[10000007];
struct dang
{
    ll val, sl;
};
dang st[maxn];
bool lt(const dang &x, const dang &y)
{
    return x.val < y.val;
}
void bs(ll c[], ll v, ll n)
{
    ll lf = 1, rt = n, mid, x;
    while(lf <= rt)
    {
        mid = (lf + rt) / 2;
        if(c[mid]*2 < v)lf = mid + 1;
        else rt = mid - 1;
    }
    if(c[lf]*2==v)--ans;
    /*x = lf;
    lf = 1, rt = n, mid;
    while(lf <= rt)
    {
        mid = (lf + rt) / 2;
        if(c[mid]*2 <= v)lf = mid + 1;
        else rt = mid - 1;
    }
    if(c[rt]*2 == v)ans -= (rt - x + 1);*/
}

ll mu(ll k, ll n)
{
    ll kq = 1;
    while(n)
    {
        if(n % 2 == 1)kq = (kq * k) % mod;
        k = (k * k) % mod;
        n /= 2;
    }
    return kq;
}
void test()
{
    //ll c[maxn], d[maxn];
    cin >> n >> k;
    ans = 0;
    for(int i = k; i > 0; i --)
    {
        a[i] = mu(k/i, n);
        for(int j = i * 2; j <= k; j += i)
            a[i] -= a[j];
        a[i] = (a[i] + mod * mod) % mod;
        ans += a[i] * i;
        ans %= mod;
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    test();
}
