#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define int long long 
#define pb push_back
#define ins insert
#define rs resize
#define br break;
#define cont continue;
#define vi vector<int>
#define vll vector<long long>
#define vvi vector<vector<int>>
#define si set<ll>
#define sll set<long long>
#define pii pair<ll,ll>
#define pll pair<long long, long long>
#define speed ios_base::sync_with_stdio(false);cin.tie(NULL);
#define vec vector
#define cend cout<<endl;
#define sc second
#define fr first
#define retz return 0;
#define ll_MAX (ll)(1e9*1e9)
#define ll_MIN (ll)(-1e9*1e9)
#define lb lower_bound
#define ub upper_bound
#define rep(i,a,b)  for(int i=a; i<=b; i++)
#define repd(i,a,b) for(int i=a; i>=b; i--)
#define ps(arr, n) for(int i=1; i<n; i++)arr[i]+=arr[i-1];
#define inp(arr, n)for(int i=0; i<n; i++)cin>>arr[i];
#define out(arr, n)for(int i=0; i<n; i++)cout<<arr[i];
#define inp1(arr,n,m)for(int i=0; i<n; i++)for(int j=0;j<m;j++)cin>>arr[i][j];
#define out1(arr,n,m)for(int i=0; i<n; i++)for(int j=0;j<m;j++)cin>>arr[i][j];
#define loop(q) for(auto it:q)
#define loop1(q) for(auto&it:q)
#define db1 cout << "*" << endl
#define db2 cout << "YES" << endl
using namespace std;
using namespace __gnu_pbds; 
#define oset(X) tree<X,null_type,less<X>, rb_tree_tag, tree_order_statistics_node_update> 
#define roset(X) tree<X,null_type,greater<X>, rb_tree_tag, tree_order_statistics_node_update>  
#define okey order_of_key //lower_bound_set
#define ofind find_by_order
#define cyes cout << "Yes" << endl; 
#define cno cout << "No" << endl;
#define mod (long long)1000000007
#define mod2 (long long)998244353
#define INT_MAX1 900000000
#define MAXN 2000000
#define INF INT_MAX



 
void solve()
{
  int n,m;
  cin >> n >> m;
  int a[n], b[n];
  rep(i,0,n-1)
    cin >> a[i] >> b[i];
  vector<int> arr[100001];
  rep(i,0,n-1)
    arr[a[i]].pb(b[i]);
  int ans = 0;
  multiset<int> q;
  rep(i,1,m)
  {
    loop(arr[i])
        q.insert(it);
    if(q.size()==0)
        continue;
    int xx = *q.rbegin();
    ans += xx;
    q.erase(q.find(xx));
  }

  cout << ans << endl;
  
  
}


signed main()
{
    
    speed;
    int t = 1;
    //cin >> t;
    while(t--)
        solve();
}