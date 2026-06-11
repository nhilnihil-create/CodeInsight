#include <bits/stdc++.h>
using namespace std;
#define END '\n'
#define int long long
#define pb push_back
#define pii pair<int, int>
#define ff first
#define ss second
#define trace(x) cerr<<x<<END;
#define loop(i, a, b) for(int i = (a); i < (b); i++)
#define loopb(i, b, a) for(int i = (b); i > (a); --i) 
const int mod = 1e9+7;
const int mod1 = 998244353;
const int inf = 9223372036854775807ll;
int power(int base,int n,int m = mod)
 {
  if(n == 0)
     return 1;
  if(n&1)
     {
      int y = power(base,n-1,m);
      return (y*base)%m;
     }
  else
     {
      int y = power(base,n/2,m);
      return (y*y)%m;
     }
 }
  
void solve()
  {
   int n,k;
   cin>>n>>k;
   int ans = 0;
   int inv2 = power(2ll,mod-2);
   loop(i,k,n+2)
     {
      int llimit = ((i%mod)*(i-1)%mod)%mod;
      llimit = (llimit*inv2)%mod;
      int ulimit_u = ((n%mod)*(n+1)%mod)%mod;
      ulimit_u = (ulimit_u *inv2)%mod;
      int ulimit_l = ((n-i)%mod*(n-i+1)%mod)%mod;
      ulimit_l = (ulimit_l *inv2)%mod;
      int local = (ulimit_u - ulimit_l + mod)%mod;
      //cerr<<llimit<<" "<<ulimit_l<<" "<<ulimit_u<<END;
      //local = (local * inv2)%mod;
      int a = (local - llimit + 1+ mod)%mod;
      ans = (ans + a)%mod;
     }
    cout<<ans;
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