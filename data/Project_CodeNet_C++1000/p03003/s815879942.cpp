#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;


ll n, m;
ll a[2005], b[2005];
ll dp[2005][2005], sum[2005][2005];
 
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> a[i];
  for(int i = 1; i <= m; i++) cin >> b[i];
 
  dp[0][0] = 1;
  for(int i = 0; i <= n; i++) sum[i][0] = 1;
  for(int i = 0; i <= m; i++) sum[0][i] = 1;
 
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <=m; j++){
      if(a[i] == b[j]) dp[i][j] = sum[i-1][j-1];
      sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + dp[i][j] + mod;
      sum[i][j] %= mod;
    }
  }
  cout << sum[n][m] << endl;
    return 0;
}
