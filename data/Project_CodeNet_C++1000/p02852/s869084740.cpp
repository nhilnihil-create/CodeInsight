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
  int N, M; cin >> N >> M;
  string S; cin >> S;
  vector<int> tmp; int res = 1;
  REP(i, N + 1) {
    if(i == 0) continue;
    if(S[i] == '0') {
      tmp.push_back(res);
      res = 1;
    } else {
      res++;
    }
  }
  int ans = 0;
  REP(i, tmp.size()) {
    if(tmp[i] > M) ans = -1;
  }
  if(ans == -1) {
    cout << ans << endl;
  } else {
    int a = 0;
    vector<int> ans2;
    for(int i = tmp.size() - 1; i >= 0; --i) {
      if(a + tmp[i] <= M) a += tmp[i];
      else {
        ans2.push_back(a);
        a = 0; a += tmp[i];
      }
      if(i == 0) ans2.push_back(a);
    }
    for(int i = ans2.size() - 1; i >= 0; --i) {
      cout << ans2[i] << " ";
    }
    cout << endl;
  }
  
}