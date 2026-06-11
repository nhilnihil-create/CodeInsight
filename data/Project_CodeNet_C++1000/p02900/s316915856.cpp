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
    int a,b;
    cin>>a>>b;
    int hcf = __gcd(a,b);
    //cerr<<hcf;
    int ans = 1;
    for(int i=2; i*i<=hcf; i++)
       {
        if(hcf%i == 0)
           {
            ans++;
            while(hcf%i == 0)
               hcf/=i;
           }
       }
  if(hcf>1)
     ans++;
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