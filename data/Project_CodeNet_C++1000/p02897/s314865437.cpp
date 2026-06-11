#include <bits/stdc++.h>
using namespace std;
#define END '\n'
#define int long long
#define pb emplace_back
#define pii pair<int, int>
#define ff first
#define ss second
#define trace(x) cerr<<x<<END;
#define loop(i, a, b) for(int i = (a); i < (b); i++)
#define loopb(i, b, a) for(int i = (b); i > (a); --i) 
const int mod = 1e9+7;
const int mod1 = 998244353;
const int inf = 92233720000000000ll;

void solve()
  {
    int n;
    cin>>n;
    int odd = ceil(n/2.0);
    double prob = 1.0*odd/n;
    cout<<fixed<<setprecision(10);
    cout<<prob;
  }
signed main()
 {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0); 
     solve();
  //cerr<<1.0*clock();
  return 0;
} 