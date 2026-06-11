#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define ss second
#define ff first
#define INF 30000000000001
#define ll_max 9000000000000000001
#define mod 1000000007
#define PI 3.14159265358979323846L
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
typedef vector<pair<ll,ll> > vll;
typedef vector<pair<int,int> > vii ;
typedef pair<ll,ll> pll;
const ll N = 100001;
const ll M = 1;

void update(ll BIT[], ll n, ll x, ll i)
{
    for(; i <= n; i += (i) & (-i)) BIT[i] += x;
}

ll query(ll BIT[], ll l)
{
    ll sum1 = 0;
    for(; l; l = l & (l - 1)) sum1 += BIT[l];
    return sum1;
}

int main()
{
    fast;
    int _ = 1;
    //cin >> _;
    while(_--)
    {
        ll n, x, y;
        cin >> n;
        pair<long double, pair<int,int> > a[2 * n];
        long double ans = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> x >> y;
            a[i].ff = atan2(y, x);
            a[i].ss.ff = x;
            a[i].ss.ss = y;
        }
        sort(a, a + n);
        for(int i = n; i < 2 * n; i++) a[i] = a[i - n], a[i].ff += 2 * PI;
        for(int i = 0; i < 2 * n; i++)
        {
            x = 0, y = 0;
            for(int j = i; j < 2 * n; j++)
            {
                x += a[j].ss.ff;
                y += a[j].ss.ss;
                if(a[j].ff - a[i].ff < PI)
                {
                    ans = max((ll)ans, x * x + y * y);
                }
                else break;
            }
        }
        ans = sqrt(ans);
        cout << fixed << setprecision(11) << ans << "\n";
    }
    return 0;
}
