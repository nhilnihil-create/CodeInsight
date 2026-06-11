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
string alpha = "abcdefghijklmnopqrstuvwxyz";
const int mod = 1e9+7;
const int mod1 = 998244353;
const int inf = 2e18+5;
const int nax = 200005;
const int mxm = 1e12;
int a[nax],f[nax];
int n,k;
void solve()
  {
   cin>>n>>k;
   loop(i,0,n)
    cin>>a[i];
   loop(i,0,n)
    cin>>f[i];
   sort(a,a+n);
   sort(f,f+n,greater<int>());
   int lo = 0,hi = mxm;
   int ans = 0;
   while(lo<=hi){
    int mid = (lo+hi)/2;
    int temp = 0;
    loop(i,0,n)
     temp += max(0ll,a[i]-mid/f[i]);
   if(temp<=k)
     hi = mid - 1;
   else
     lo = mid + 1;
   }
   cout<<lo;
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