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
const int inf = 92233720368ll;
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
unordered_map<int,int> cache;
int modinv(int x)
 {
  if(cache[x] != 0)
     return cache[x];
  int ans = power(x,mod-2);
  cache[x] = ans;
  return ans;
 }
int nCr(int k, int n)
{
  if (n < k) return 0;
  if (k > n / 2) k = n - k;
  int ret = 1;
  int divider = 1;
  loop(i,0,k) 
  {
   ret = ret * (n - i) % mod;
   divider = divider * (i + 1) % mod;
  }
  return (ret * modinv(divider))% mod;
}
void solve()
 { 
  int n,a,b;
  cin>>n>>a>>b;
  int tot = power(2ll,n);
  tot = (tot - 1ll + mod)%mod;
  //cerr<<tot;
  int a_reduce = nCr(a,n);
  int b_reduce = nCr(b,n);
  int reduce = (a_reduce + b_reduce)%mod;
  //cerr<<a_reduce<<" "<<b_reduce<<" "<<tot;
  tot= (tot - reduce + mod)%mod;
  cout<<tot;
 }
signed main()
 {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 
   /*int t;
   cin>>t;
   while(t--)*/
     solve();
  //cerr<<END<<1.0*clock();
  return 0;
} 