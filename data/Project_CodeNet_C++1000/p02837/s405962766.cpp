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
  int N; cin >> N;
  vector<int> A(N); vector<vector<int>> x(N), y(N);
  REP(i, N) {
    int a; cin >> a;
    A[i] = a;
    REP(k, A[i]) {
      int X, Y; cin >> X >> Y;
      x[i].push_back(X); y[i].push_back(Y);
    }
  }
  int ans = 0;
  for(int bit = 0; bit < (1 << N); bit++) {
    bool flag = false;
    for(int i = 0; i < N; ++i) {
      if(!( bit & (1 << i) )) continue;
      // 1: 正直 0: 嘘つき
      REP(k, A[i]) {
        if(y[i][k] == 1) {
          if(bit & (1 << (x[i][k] - 1))) {

          } else {
            flag = true;
          }
        } else {
          if(bit & (1 << (x[i][k] - 1))) {
            flag = true;
          }
        }
      }
    }
    if(flag) continue;
    int res = __builtin_popcount(bit);
    if(ans < res) ans = res;
  }
  cout << ans << endl;
}
