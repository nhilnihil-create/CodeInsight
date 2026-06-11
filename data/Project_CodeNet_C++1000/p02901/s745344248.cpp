#include <iostream>
#include <set>

using namespace std;

typedef long long ll;

const int INF = 1e7;
ll n, m, ans;
ll dp[1<<15];

int main() {
  cin >> n >> m;  
  
  for (int bit = 1; bit < (1<<n); bit++) {
    dp[bit] = INF;
  }
  
  for (int i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;
    ll bit = 0;
    for (int j = 0; j < b; j++) {
      ll c;
      cin >> c;
      c--;
      bit += (1<<c);
    }
    dp[bit] = min(dp[bit], a);
  }
  
  for (int bit1 = 1; bit1 < (1<<n)-1; bit1++) {
    for (int bit2 = bit1+1; bit2 < (1<<n); bit2++) {
      dp[bit1 | bit2] = min(dp[bit1 | bit2], dp[bit1] + dp[bit2]);
    }
  }
  
  ans = (dp[(1<<n)-1] == INF) ? -1 : dp[(1<<n)-1]; 
  cout << ans << endl;
  return 0;
}
