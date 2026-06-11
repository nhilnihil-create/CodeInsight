#include <bits/stdc++.h>
using namespace std;
#define END '\n'
#define int unsigned long long
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

void solve()
  {
   int n,k;
   cin>>n>>k;
   int cnt = 0;
   loop(i,0,n)
    {
      int x;
      cin>>x;
      cnt += (x>=k);
    }
    cout<<cnt;
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