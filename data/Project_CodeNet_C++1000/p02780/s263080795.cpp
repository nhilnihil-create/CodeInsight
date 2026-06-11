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
const int inf = 1e18;
const int nax = 200005;
int a[nax],n,k;
void solve()
 {
  cin>>n>>k;
  loop(i,0,n)
   cin>>a[i];
  int lo = 0,hi = 0;
  double sum = 0,ans = 0;
  loop(i,0,k)
   sum += 1.0*(a[i]+1)/2;
  ans = sum;
  hi = k -1;
  loop(i,k,n)
   {
	   sum -= 1.0*(a[lo]+1)/2;
	   lo++;
	   sum += 1.0*(a[i]+1)/2;
	   hi++;
	   if(hi - lo + 1 == k)
	    ans = max(ans,sum);
   }
  cout<<fixed<<setprecision(10);
  cout<<ans;
   
  
 }  
signed main()
 {   
  ios_base::sync_with_stdio(false);
  cin.tie(0); 
  cout.tie(0); 
   /*int t;
   cin>>t;
   loop(i,1,t+1)*/
      solve();
      
  //cerr<<END<<1.0*clock();
  return 0;
} 
