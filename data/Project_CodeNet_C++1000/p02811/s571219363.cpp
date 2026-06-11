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
const int inf = INT_MAX;
bool mywish(const pii &a,const pii &b)
  {
    return a.first > b.first;
  }

void solve()
  {
   int k,x;
   cin>>k>>x;
   cout<<(500ll*k >= x ? "Yes" : "No");
  } 
signed main()
 {
  
  /* int t;
   cin>>t;
   while(t--)*/
     solve();
  //cerr<<END<<1.0*clock();
  return 0;
} 