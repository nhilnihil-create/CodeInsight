#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define mp make_pair
#define pb(x) push_back(x)
#define vll vector<long long>
#define pll pair<long long, long long>
#define mll map<long long, long long>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define gcd __gcd
#define clr(x) memset(x, 0, sizeof(x))
#define mod 1000000007LL
#define mod2 998244353LL
#define INF 1e18

typedef long long ll;
typedef long double ld;
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> o_tree;

// if we convert that bound day to x ,then person cant work for k days in any possilbe way
// bound day is o

void solve()
{
    ll x, y, a, b, c;
    cin >> x >> y >> a >> b >> c;
    ll i, j;
    // eat x and y apples
    ll red[a], green[b];
    vll cless(c);
    for (i = 0; i < a; i++)
    {
        cin >> red[i];
    }
    for (i = 0; i < b; i++)
    {
        cin >> green[i];
    }
    for (i = 0; i < c; i++)
    {
        cin >> cless[i];
    }
    sort(red, red + a);
    reverse(red, red + a);
    sort(green, green + b);
    reverse(green, green + b);
    sort(cless.begin(), cless.end());
    vll xx(x), yy(y);
    for (i = 0; i < x; i++)
    {
        xx[i] = red[i];
    }
    for (i = 0; i < y; i++)
    {
        yy[i] = green[i];
    }
    ll res = 0;
    while (!xx.empty() && !yy.empty())
    {
        if (cless.empty())
            break;
        ll now = cless.back();
        if (min(xx.back(), yy.back()) > cless.back())
            break;
        if (xx.back() < yy.back())
        {
            xx.pop_back();
            res += now;
            cless.pop_back();
        }
        else
        {
            yy.pop_back();
            cless.pop_back();
            res += now;
        }
    }
    while (!xx.empty())
    {
        if (!cless.empty())
        {
            if (cless.back() > xx.back())
            {
                res += cless.back();
                xx.pop_back();
                cless.pop_back();
            }
            else
            {
                res += xx.back();
                xx.pop_back();
            }
        }
        else
        {
            res += xx.back();
            xx.pop_back();
        }
    }
    while (!yy.empty())
    {
        if (!cless.empty())
        {
            if (cless.back() > yy.back())
            {
                res += cless.back();
                yy.pop_back();
                cless.pop_back();
            }
            else{
                res += yy.back();
            yy.pop_back();        
            }
        }
        else
        {
            res += yy.back();
            yy.pop_back();
        }
    }
    cout << res << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (fopen("input.txt", "r"))
    {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    }
    cout << setprecision(20);

    ll t = 1;

    // cin>>t;

    while (t--)
    {
        solve();
    }

    return 0;
}