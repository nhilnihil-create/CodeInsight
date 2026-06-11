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
const int nax = 200005;
const int mxm = 2019;
int suff[nax],r[mxm];
int n;
string s;
void solve()
 {
  cin>>s;
  n = s.size();
  int cnt = 0;
  suff[n] = 0;
  int p = 1;
  memset(r,0,sizeof r);
  r[0] = 1;
  loopb(i,n-1,-1)
   {
    p %= mxm;
    int now = ((s[i] - '0')*p)%mxm;
    p *= 10;
    suff[i] = (now + suff[i+1])%mxm;
    r[suff[i]]++;
   }
  loop(i,0,2019)
   cnt += r[i]*(r[i] - 1)/2;
  cout<<cnt;
 } 
int32_t main()
 {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 
   /*int t;
   cin>>t;
   while(t--)*/
     solve();
 // cerr<<END<<1.0*clock()/CLOCKS_PER_SEC;
  return 0;
} 