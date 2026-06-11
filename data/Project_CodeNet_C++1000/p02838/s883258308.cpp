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
  cin>>n;
  ll i,j;
  ll a[n];
  for(i=0;i<n;i++)
  {
    cin>>a[i];
  } 
  ll freq[63];
  clr(freq);
  ll res=0;
  for(i=0;i<n;i++)
  {
    for(j=0;j<=60;j++)
    {
      ll no = 1ll<<j;
      no&=a[i];
      if(no==0)
      {
        ll tans = (1ll<<j);
        tans%=mod;
        tans*=freq[j];
        tans%=mod;
        res+=tans;
        res%=mod;
      } 
      else{
        // cout<<a[i]<<" "<<j<<"\n";
        ll tans = (1ll<<j);
        tans%=mod;
        tans*=(i-freq[j]);
        tans%=mod;
        res+=tans;
        res%=mod;
        freq[j]++;
      }
    }
  }
  cout<<res<<"\n";
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