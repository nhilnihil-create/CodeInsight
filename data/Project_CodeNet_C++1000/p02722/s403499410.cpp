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

void solve()
{
    ll n;
    cin >> n;
    if (n == 2)
    {
        cout << "1\n";
        return;
    }
    ll res = 0;
    vll fact;
    ll i;
    for (i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            fact.pb(i);
            if (i * i != n)
            {
                fact.pb(n / i);
            }
        }
    }
    fact.pb(n);
    ll n2 = n-1;
    vll fact2;
    for (i = 2; i * i <= n2; i++)
    {
        if (n2 % i == 0)
        {
            fact2.pb(i);
            if (i * i != n2)
            {
                fact2.pb(n2 / i);
            }
        }
    }
    fact.pb(n2);
    res+=sz(fact2);
    for (auto it : fact)
    {
        ll noo = n / it;
        ll nn =n;
        while(nn%it==0)
        {
            nn/=it;
        }
        if(nn%it==1)
        {
            res++;
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