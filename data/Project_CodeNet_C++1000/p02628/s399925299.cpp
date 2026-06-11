#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Common file
#include <ext/pb_ds/assoc_container.hpp>
// Including tree_order_statistics_node_update
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>



#define pb push_back
#define F first
#define S second
#define rep(i,n) for(int i = 0; i < (n); i++)

using ll = long long;
using ld = long double;
using ul = unsigned long long;
using ii = pair<int, int>;
#define Mosta     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ReadFile            freopen("input.in","r",stdin)
#define WriteFile           freopen("output.txt","w",stdout)
const ll mod7 = 1000000007,mod = 1000000000,OO = 0x3f3f3f3f;
const ld EPS = 1e-7;
double Pi=acos(-1);
const ld rad=Pi/180.0;
ll power(ll x, ll y, ll p)
{
    ll res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
            y = y>>1;
            x = (x*x) % p;
    }
    return res;
}
ll nCr (ll n,ll m)
{
    return(m == 0)?1:n*nCr(n-1,m-1)/m;
}

/*****************************************************/

const int N = 1005;
int a[N] , n , k , ans = 0;

int main()
{
    cin >> n >> k;

    for(int i = 0; i < n; ++i)
        cin >> a[i];

    sort(a , a + n);

    for(int i = 0; i < k; ++i)
        ans += a[i];

    cout << ans << "\n";

    return 0;
}
