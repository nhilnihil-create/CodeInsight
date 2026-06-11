#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define speed                     \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define ll long long
#define pb push_back
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define endl "\n"
#define mod 1000000007
#define mod1 998244353
#define ff first
#define ss second
#define MAX 500005
#define N 10004
#define INF 1000000009
#define all(v) v.begin(), v.end()
#define sbit(a) __builtin_popcount(a)
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
typedef pair<ll, ll> pll;
typedef pair<pll, ll> ppl;
typedef map<ll, ll> mpll;
typedef map<vector<ll>, ll> mpvl;
ll power(ll x, ll y, ll p)
{
    ll res = 1;

    x = x % p;

    if (x == 0)
        return 0;
    while (y > 0)
    {

        if (y & 1)
            res = (res * x) % p;

        y = y >> 1;
        x = (x * x) % p;
    }

    return res;
}
void solve()
{

   ll n;
   cin>>n;
   ll ans=0;
   for(ll i=1;i<=n-1;i++)
   {
       ll j=1;
       while(i*j<n)//time complexity=n*(1/1+1/2+1/3+.....)=n*log(logn)
       {
          ans++;
          j++;
       }
   }
   cout<<ans<<endl;
}
int main()
{
    speed;
    ll kk;
    kk = 1;
    //cin >> kk;
    while (kk--)
    {

        solve();
    }

    return 0;
}