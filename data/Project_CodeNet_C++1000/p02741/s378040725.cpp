

#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
using namespace std;
const ll maxn = 1e6 + 7;
const ll mod = 1e9 + 7;
const ll mod1 = 123456789;
const int maxx = 1005;
ll q, t, n, m, T, k, ans, a[maxn], b[maxn];
priority_queue<ll> pr;
string s, str;
char ss[maxx][maxx];

struct dang
{
    ll val, sl;
};
dang st[maxn];
bool lt(const dang &x, const dang &y)
{
    return x.val < y.val;
}


void test()
{
    //ll c[maxn], d[maxn];
ll    f[32] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    cin >> n;
    cout << f[n-1];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    test();
}
