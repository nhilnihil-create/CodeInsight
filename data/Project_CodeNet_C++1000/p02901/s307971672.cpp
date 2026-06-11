#include <bits/stdc++.h>
using namespace std;
#define END '\n'
#define int long long
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
#define loop(i, a, b) for(int i = (a); i < (b); i++)
#define loopb(i, b, a) for(int i = (b); i > (a); --i)
const int mod = 1e9+7;
const int mod1 = 998244353;
const int inf = 2e18+5;
const int nax = 1<<12;
const int mxm = 1001;
int dp[nax],locks[mxm],cost[mxm],n,m,sz,l;
void solve()
  {
   cin>>n>>m;
   loop(i,0,m)
    {
      cin>>cost[i]>>sz;
      loop(j,0,sz)
       {
        cin>>l;
        l--;
        locks[i] |= (1<<l);
       }
    }
   dp[0] = 0;
   loop(i,1,(1<<n))
    {
      dp[i] = inf;
      loop(j,0,m)
       {
        int left = (i^locks[j])&i;
        dp[i] = min(dp[i],dp[left]+cost[j]);
       }
    }
  if(dp[(1<<n)-1] == inf)
     dp[(1<<n)-1] = -1;
   cout<<dp[(1<<n)-1];
  }
signed main()
 {
   
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 
    solve();    
  //cerr<<END<<1.0*clock();
  return 0;
} 