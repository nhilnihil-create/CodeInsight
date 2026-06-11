#include <bits/stdc++.h>

typedef unsigned long long int ull;
typedef long double ldb;
typedef long long int ll;

#define MOD1        1000000007
#define MOD2        998244353
#define PI          3.1415926535897932384626433832795
#define FILL(a, value) memset(a, value, sizeof(a))
#define BOOST       ios_base::sync_with_stdio(false); cin.tie(NULL)
#define what_is(x)  cerr << #x << " is " << x << endl;
#define ASSERT(left,operator,right) { if(!((left) operator (right))){ std::cerr << "ASSERT FAILED: " << #left << #operator << #right << " @ " << __FILE__ << " (" << __LINE__ << "). " << #left << "=" << (left) << "; " << #right << "=" << (right) << std::endl; } }

#define rep01(k,n)      for (ll i=k; i<n; i++)
#define rep02(k,n)      for (ll j=k; j<n; j++)
#define rep03(k,n)      for (ll k=k; k<n; k++)
#define rep11(k,n)      for (ll i=k; i<=n; i++)
#define rep12(k,n)      for (ll j=k; j<=n; j++)
#define rep13(k,n)      for (ll k=k; k<=n; k++)
#define repIT(c,it)     for(typeof(c.begin()) it = c.begin(); it != c.end(); ++it)
#define all(c)      c.begin(), c.end()

using namespace std;

const double pi = acos(-1.0);
const double epsilon = 1e-9;        // Add epsilon when casting double to int to avoid rounding pitfall issues, eg, 0.94*8178 in int
const int maxn = 1e6+10;

void solve()
{
    ll n;
    cin >> n;
    priority_queue<double, vector<double>, greater<double>> v;

    for(int i = 0; i < n; i++)
    {
        double el;
        cin >> el;
        v.push(el);
    }

    while(v.size() > 1)
    {
        double e1 = v.top(); v.pop();
        double e2 = v.top(); v.pop();
        v.push((e1+e2)*0.5);
    }
    cout << fixed;
    cout << setprecision(14) << v.top();

}

int main()
{
    int t = 1;
    //cin >> t;
    while(t--)
        solve();

    cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
    return 0;
}