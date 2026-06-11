#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define owo ios_base::sync_with_stdio(0);cin.tie(0);
#define MOD (ll)(1e6+3)
#define INF (ll)(1e18)
#define debug(...) fprintf(stderr, __VA_ARGS__),fflush(stderr)
#define time__(d) for(long blockTime = 0; (blockTime == 0 ? (blockTime=clock()) != 0 : false);\
debug("%s time : %.4fs\n", d, (double)(clock() - blockTime) / CLOCKS_PER_SEC))
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> PII;
typedef pair<int,int> pii;
typedef vector<vector<int>> vii;
typedef vector<vector<ll>> VII;
int main()
{
   int n;
   cin>>n;
  int ans = 0;
  vector<ll>a(n),b(n),c(n+1);
      for(int i=0;i<n;i++)cin>>a[i];
      for(int i=0;i<n;i++){cin>>b[i];ans+=b[i];}
      for(int i=1;i<=n-1;i++)cin>>c[i];
      for(int i=0;i<n-1;i++)
      {
        if(a[i+1]-a[i] == 1)ans+=c[a[i]];
      }
  cout<<ans;
  
}