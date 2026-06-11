
#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
//cout << fixed << setprecision(8) << a << endl;
#define Fast_Input ios_base :: sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
#define pb push_back
#define mem(a, b)     memset(a, b, sizeof(a))
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef tree<int,null_type,greater<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
/*sort(v.begin(), v.end(),
     [](const pair<int, int>& x, const pair<int, int>& y)
{
    if (x.first != y.first)
        return x.first < y.first;
    return x.second < y.second;
});
*/
int const fx[]= {+1,+0,-1,+1};
int const fy[]= {-1,+1,+0,+0};
const int inf = numeric_limits<int>::max();
const int mx=1e9;
const ll mod=1e9+7;
ll pow(ll x,ll n)
{
    ll res=1;
    while(n)
    {
        if(n%2)
        {
            res=((res%mod)*(x%mod))%mod;
            n--;
        }
        x=((x%mod)*(x%mod))%mod;
        n/=2;
    }
    return res;
}
int main()
{
    ll n,i;
    cin >> n;
    ll one=pow(ll(10),n);
    ll zero=pow(ll(9),n);
    ll nine=zero;
    ll intersection=pow(ll(8),n);
    ll z=(zero+nine-intersection)%mod;
    ll ans=(one-z)%mod;
    if(ans<0)ans+=mod;
    cout << ans << endl;
    return 0;
}


