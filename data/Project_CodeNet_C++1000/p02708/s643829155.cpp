#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
const int inf = 1001001001;
const int mod = 1000000007;


//yet solved 2020/8/15

int main(){
  int n,k;
  cin >> n >> k;

  vector<int> cum(n+2);
  // com = {0,0,1,3,...}index 1~n+1
  rep(i,n) {
    cum[i+2] = cum[i+1] + i+1;
    cum[i+2] %= mod;
  }

  int ans = 0;
  for(int i = k; i <= n+1; i++){
    int mx = cum[n+1]-cum[n+1-i];
    int mn = cum[i]-cum[0];
    ans += (mx - mn + 1 + mod)%mod;
    ans %= mod;
  }
  cout << ans << endl;
}
