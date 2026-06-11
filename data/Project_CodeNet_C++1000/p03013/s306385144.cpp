#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long INF = 1LL << 60;
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

ll mod = 1000000007;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> a(21000000);
    for(int i = 0; i < M; i++) cin >> a[i];
    vector<ll> dp(21000000);
    for (int i = 0; i < 21000000; i++) dp[i] = INF;
    for (int i = 0; i < M; i++){
      dp[a[i] - 1] = 0;
    }
      if (a[0] == 1)
        dp[0] = 0;
      else
        dp[0] = 1;
    if ((a[0] == 1 && a[1] == 2)||a[0]==2) dp[1] = 0;
    else  if(a[0]==1 && a[1]!=2)dp[1] = 1;
    else
      dp[1] = 2;
    for (int i = 2; i < N; i++) {
      if (dp[i] == 0) continue;
      else
        dp[i] = (dp[i - 1]%mod + dp[i - 2]%mod)%mod;
    }
    cout << dp[N - 1]%mod << endl;
    return 0;
}