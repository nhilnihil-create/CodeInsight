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
  int M, D; cin >> M >> D;
  int a, b; cin >> a >> b;
  int ans = 0;
  if(M == 4 || M == 6 || M == 9 || M == 11) {
    if(D == 30) {
      ans = 1;
    }
  } else if(M == 2) {
    if(D == 28) {
      ans = 1;
    }
  } else {
    if(D == 31) {
      ans = 1;
    }
  }
  cout << ans << endl;
}