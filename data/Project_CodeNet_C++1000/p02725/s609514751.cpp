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
const int mod = 1e9+7;
const int mod1 = 998244353;
const int inf = 9223372037ll;
const int nax = 200005;
int a[nax],n,k;
void solve()
  {
   cin>>k>>n;
   int mx = 0;
   loop(i,0,n)
    cin>>a[i];
   loop(i,1,n)
    mx = max(mx,a[i]-a[i-1]);
   mx = max(a[0]+k-a[n-1],mx);
   cout<<k-mx;
  } 
signed main()
 {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
     solve();
  //cerr<<END<<1.0*clock();
  return 0;
} 