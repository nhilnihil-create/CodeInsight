#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;

const int mod=1e9+7;
const int inf=-1;
const int sz=2e5;

#define pi acos(-1)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define gap ' '
#define lb lower_bound
#define ub upper_bound
#define SIN(x) sin(x * pi / 180.0)
#define COS(x) cos(x * pi / 180.0)
#define clr(x) memset(x,0,sizeof(x))
#define all(x) sort(x.begin(),x.end())
#define rall(x) reverse(x.begin(),x.end())
#define dbg puts("finding wrong")
#define case(x,y) printf("Case %lld: %lld\n",++x,y)
#define fastio ios::sync_with_stdio(false);cin.tie(0)


int ar[sz];

int main()
{
  fastio;
  ll n, x, y, i;
  cin>>n;
  set<ll>v1,v2;
  for(i=0; i<n; i++)
  {
      cin>>x>>y;
      ll p=x+y;
      ll q=x-y;
     v1.insert(p);
     v2.insert(q);
  }
  ll ans=max((*v1.rbegin()-*v1.begin()),(*v2.rbegin()-*v2.begin()));
  cout<<ans<<endl;
}
