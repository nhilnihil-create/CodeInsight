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

int dp[200005][2];
void solve()
{
  
  string s;
  cin >> s;
  
  int n = sz(s),an=-1;

  
  if(s[0]=='D')dp[0][1]=1,an=1;
  else if(s[0]=='?')s[0]='D',dp[0][1]=1;  
  forf(i,1,n)
  {
    if(s[i]=='P')
    {
       dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
       an = max(an,dp[i][0]);

    }else if(s[i]=='D')
    {
       if(s[i-1]=='P') dp[i][1] = dp[i-1][0]+2;
       else if(s[i-1]=='D') dp[i][1] = dp[i-1][1]+1;
       else dp[i][1] = max(dp[i-1][0]+2,dp[i-1][1]+1); 
       
       an = max(dp[i][1],an);
    }else
    {
      dp[i][0] = max(dp[i-1][0],dp[i-1][1]);
      dp[i][1] = max(dp[i-1][0]+2,dp[i-1][1]+1);
      if(dp[i][0] > dp[i][1]) s[i]='P';
      else s[i]='D';
    }
  }

  cout<<s;

}

int32_t main()
{
  pr_init();
  fastio;
  solve();

 }
      