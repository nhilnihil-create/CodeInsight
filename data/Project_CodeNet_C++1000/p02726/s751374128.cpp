#include <bits/stdc++.h>
using namespace std;
#define END '\n'
#define int long long
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
#define bug(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
#define loop(i, a, b) for(int i = (a); i < (b); i++)
#define loopb(i, b, a) for(int i = (b); i > (a); --i) 
const int inf = 5e18;  
const int mod = 1e9+7;
const int mod1 = 998244353;
const int nax = 2005;
int n,x,y,dist[nax];
void solve()
 {
  cin>>n>>x>>y;
  loop(i,1,n+1)
   loop(j,i+1,n+1)
     {
      int d = min({j-i,abs(x-i) + abs(j-y) + 1,abs(x-j) + abs(y-i) + 1});
      dist[d]++;
     }
  loop(i,1,n)
   cout<<dist[i]<<END;
 } 
signed main()
 {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 
     solve();
 // cerr<<END<<1.0*clock()/CLOCKS_PER_SEC;
  return 0;
} 