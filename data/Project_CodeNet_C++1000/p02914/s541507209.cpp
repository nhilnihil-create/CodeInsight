#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define db long double
#define ii pair<int,int>
#define vi vector<int>
#define fi first
#define se second
#define sz(a) (int)(a).size()
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define FN(i, n) for (int i = 0; i < (int)(n); ++i)
#define FEN(i,n) for (int i = 1;i <= (int)(n); ++i)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define repv(i,a,b) for(int i=b-1;i>=a;i--)
#define SET(A, val) memset(A, val, sizeof(A))
typedef tree<int ,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set ;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif
const int N=100005;
int n;
ll a[N],b[N];
ll solve()
{
  int ind=1;
  repv(i,0,60)
    {
      int mxind=ind;
      ll mx=-1;
      rep(j,ind,n+1)
	{
	  if(((a[j]>>i)&1) && a[j]>mx)
	    mxind=j,mx=a[j];
	}
      if(mx==-1) continue;
      swap(a[mxind],a[ind]);
      mxind=ind;
      rep(j,1,n+1)
	{
	  if(j!=mxind && ((a[j]>>i)&1) )
	    a[j]=(a[j]^a[mxind]);
	}
      ind++;
    }
  ll ans=0;
  rep(i,1,n+1) ans^=a[i];
  return ans;
}
int main()
{
  std::ios::sync_with_stdio(false);
  cin.tie(NULL) ; cout.tie(NULL) ;
  cin>>n;
  ll tot=0;
  rep(i,1,n+1) cin>>a[i],b[i]=a[i],tot^=a[i];
  rep(j,0,60)
    {
      if(!((tot>>j)&1) ) continue;
      rep(i,1,n+1)
	{
	  if((a[i]>>j)&1) a[i]-=((ll)1<<j);
	}
    }
  ll best=solve();
  cout<<best+(tot^best)<<endl;
  return 0 ;
}
