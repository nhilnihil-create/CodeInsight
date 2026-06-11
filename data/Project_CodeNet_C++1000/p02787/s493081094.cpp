#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
string char_to_string(char val) {
  return string(1, val);
}
int char_to_int(char val) {
  return val - '0';
}
template<class T> inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template<class T> inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
int vector_finder(std::vector<ll> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

int main() {
  int H, N; cin >> H >> N;
  vector<int> A(N), B(N); REP(i, N) cin >> A[i] >> B[i];
  const int INF = pow(10, 9) + 7; vector<int> dp(H * H + H, INF);
  dp[0] = 0;
  REP(i, H + 1) {
    REP(k, N) {
      dp[i + A[k]] = min(dp[i] + B[k], dp[i + A[k]]);
    }
  }
  ll ans = pow(10, 9) + 7;
  for(int i = H; i < H * H + H; ++i) {
    if(dp[i] != INF) {
      if(ans > dp[i]) ans = dp[i];
    }
  }
  cout << ans << endl;
}