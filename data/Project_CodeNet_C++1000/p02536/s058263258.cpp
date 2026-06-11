#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define req(i,a,b) for(ll i=(a);i>=(b);--i)
#define name "a"
#define pb push_back
#define sz size()
#define ff first
#define ss second
#define xd '\n'
#define dc " "
typedef pair < ll , ll > ii;
const ll maxn = 1e5+7, oo = 1e18, base = 311, mod = 1e9+7;
const double PI = 3.141592654;
ll t, n, m, x[maxn], y[maxn], res, hang[maxn], cha[maxn];
ll goc(int i)
{
    if (i != cha[i])
        cha[i] = goc(cha[i]);
    return cha[i];
}
bool hopnhat(int x, int y)
{
    x = goc(x);
    y = goc(y);
    if (x == y)
        return false;
    if (hang[x] == hang[y])
        ++hang[x];
    if (hang[x] > hang[y])
        cha[y] = x;
    else cha[x] = y;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    cin >> n >> m;
    rep (i, 1, m)
        cin >> x[i] >> y[i];
    rep (i, 1, n)
        hang[i] = 0, cha[i] = i;
    rep (i, 1, m)
    {
        if (hopnhat(x[i], y[i]))
            ++res;
    }
    cout << n - 1 - res;
}
