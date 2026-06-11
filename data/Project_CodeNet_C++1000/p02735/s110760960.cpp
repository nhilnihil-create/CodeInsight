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
 #define M          998244353
 #define forf(i,a,b) for(int i=a;i<b;i++)
 #define it(x)      x::iterator
 #define ll         long long 
 #define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
 #define time__(d)  for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false); debug("%s time : %.4fs", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
 #define vii        vector<int>
 #define big        1e18
 #define sm         -1e9
 #define mkr        make_pair
 #define vpi        vector<pair<int,int> >
 #define pii        pair<int,int>
 #define rng        500005
 #define sz(x)      (int)x.size()
 #define rv(x)      reverse(x.begin(),x.end())
 #define out(x)     cout<<x.fi<<" "<<x.se<<endl;

#define ordered_set tree<pii, null_type,less<pii>, rb_tree_tag,tree_order_statistics_node_update> 
  
void pr_init()
{
   
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
   
    #endif
}

vector<vector<char> >vmt;
vector<vii> dp;
void solve()
{
  
  int h,w;
  cin >> h >> w;
  
  vmt.assign(h,vector<char>(w,'a'));
  dp.assign(h,vii(w,0));

  forf(i,0,h)
  {
    forf(j,0,w) cin >> vmt[i][j];
  }
  
  if(vmt[h-1][w-1]=='.') dp[h-1][w-1]=0;
  else dp[h-1][w-1]=1;

  for(int i=1;i < h+w ;i++)
  {
    for(int j=0;j<h;j++)
    {
      for(int k=0;k<w;k++)
      {
         if(abs(h-1-j)+abs(w-1-k) == i)
         {
          int vl = big;
           if(k+1<w)
           {
            if(vmt[j][k]=='.' || vmt[j][k+1]=='#') vl = min(vl,dp[j][k+1]);
            else vl = min(vl,dp[j][k+1]+1);
           }
           if(j+1<h)
           {
            if(vmt[j][k]=='.' || vmt[j+1][k]=='#') vl = min(vl,dp[j+1][k]);
            else vl = min(vl,dp[j+1][k]+1);
           }
           dp[j][k] = vl;
         }
      }
    }
  }



  cout<<dp[0][0]<<endl;

}

int32_t main()
{
  //pr_init();
  fastio;
  
  auto start = high_resolution_clock::now(); 
 
  solve();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start); 
  
    // cout << "Time taken by function: "
    //      << duration.count() << " microseconds" << endl; 

 }