#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long int
#define vi vector<int>
#define vii vector<pair<int,int>>
#define pi pair<int,int>
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back
#define pf push_front
#define deb(x) cerr<<#x<<" : "<<x<<endl;
#define fi first
#define se second
#define mi map<int,int>
#define PI   3.141592653589
#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define f(i,x,n) for(int i=x;i<n;i++)
#define rf(i,x,n) for(int i=n;i>=x;i--)
#define check(x)   cerr<<#x<<" : "<<x<<endl;
#define ordered_set tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update>
#define fbo find_by_order
#define ook order_of_key
#define baar exit(0)
using namespace __gnu_pbds;
using namespace std;
int powmod(int base,int exponent)
{
	int ans=1;
	while(exponent){
		if(exponent&1)ans=(ans*base);
		base=(base*base);
		exponent/=2;
	}
	return ans;
}
vi v[100005],vis(100005);
void dfs(int x)
{
	vis[x]=1;
	for(int y:v[x])
	{
		if(!vis[y]) dfs(y);
	}
}
signed main()
{
  fast
  int n,m;
  cin>>n>>m;
  f(i,0,m)
  {
  	int x,y;cin>>x>>y;
  	v[x].pb(y);
  	v[y].pb(x);
  }
  int cnt=0;
  f(i,1,n+1)
  {
  	if(!vis[i])
  	{
  	   cnt++;
		 dfs(i);	
	}
  }
  cout<<cnt-1;
  cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
  return 0;
}
 