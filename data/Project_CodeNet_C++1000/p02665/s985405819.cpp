 #include<bits/stdc++.h>
 #include <ext/pb_ds/tree_policy.hpp>
 #include <ext/pb_ds/assoc_container.hpp>
 #include<chrono>
 using namespace std;
 using namespace std::chrono;      
 using namespace __gnu_pbds; 
 #define fastio     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
 #define fi         first
 #define se         second
#define int         long long 
 #define pb         push_back
 #define emp        emplace_back
 #define vv(x)      vector<x>
 #define mp(x,y)    map<x,y>
 #define dq(x)      deque<x>
 #define pql(x)     priority_queue<x>
 #define pqs(x)     priority_queue<x,vv(x),greater<x> >
 #define M          1000000007
 #define forf(i,a,b) for(int i=a;i<b;i++)
 #define it(x)      x::iterator
 #define ll         long long 
 #define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
 #define time__(d)  for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
 #define vii        vector<int>
 #define big        3e18
 #define sm         -2e9
 #define mkr        make_pair
 #define vpi        vector<pair<int,int> >
 #define pii        pair<int,int>
 #define rng        500005
 #define sz(x)      (int)x.size()
 #define rv(x)      reverse(x.begin(),x.end())
 #define out(x)     cout<<x.fi<<" "<<x.se<<endl;

//#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> 
  
void pr_init()
{
   
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
   
    #endif
}

int ar[100005] , dp[100005];
void solve()
{
  
  int n;
  cin >> n;

  forf(i,0,n+1) cin >> ar[i];

  for(int i=n;i>=0;i--)
  {
    if(i==n) dp[i]=ar[i];
    else dp[i] = ar[i]+dp[i+1];
  }

  int an = 0 , bl=0,cur=1;
  

  for(int i=0;i<=n;i++)
  {
    if(cur < ar[i]) bl=1;
    cur = min(dp[i],cur);
    an += cur;
    cur-=ar[i];
    cur*=2;
  }

  
  if(bl)
  {
    cout<<"-1\n";
    return ;
  }

  cout<<an<<endl;

}

int32_t main()
{
  pr_init();
  fastio;
  solve();

 }
      