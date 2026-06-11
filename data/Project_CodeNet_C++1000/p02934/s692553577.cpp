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
 
void solve()
  {
   int n;
   cin>>n;
   double sum = 0.0;
   //vector<int> v(n);
   loop(i,0,n)
    {
      int x;
      cin>>x;
      sum += (1.0/x);
    }
   sum = 1.0/sum;
   cout<<fixed<<setprecision(10);
   cout<<sum;
  } 
signed main()
 {
 
     solve();
  //cerr<<END<<1.0*clock();
  return 0;
} 