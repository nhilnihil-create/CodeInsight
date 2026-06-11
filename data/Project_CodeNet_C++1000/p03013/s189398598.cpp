//DP

#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
const int mod = 1000000007;

/*
auto f(ll x){
  if (x == 1) return 1;
  if (x == 2) return 2;
  else return (f(x - 1) + f (x - 2)) % mod;
}
*/

int main(void){
  int N, M;
  cin >> N >> M;
  vector <int> broken(N + 1);
  rep(i,M){
    int a;
    cin >> a;
    broken[a] = 1;
  }
  vector <int> dp(N + 2);  //N-1段目が壊れていた時に配列外参照で困らないようにするため
  dp[N] = 1;
  for (int i = N - 1; i >= 0; i--){
    if (broken[i]){
      dp[i] = 0;
      continue;
    }
    dp[i] = (dp[i + 1] + dp[i + 2]) % mod;
  }
  cout << dp[0] << endl;
  /*
  //x段を登る移動方法の総数
  ll ans = 1;
  rep(i,M){
    cin >> a[i];
    if (i > 0){
      if (a[i] == a[i - 1] + 1){
        cout << 0 << endl;  //連続で床が壊れていたら0を出力して終了
        return 0;
      }
      ans *= f(a[i] - a[i - 1]);
      ans %= mod;
    }
  }
  cout << ans << endl;
  */
  return 0;
}
