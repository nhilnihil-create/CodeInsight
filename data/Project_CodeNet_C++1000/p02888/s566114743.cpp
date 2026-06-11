#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
using P = pair<ll, ll>;
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
struct edge {
  ll to, cost;
};

vector<int> L; 

int main() {
  int N; cin >> N;
  L.resize(N); REP(i, N) cin >> L[i];
  sort(all(L)); // にぶたん？
  ll ans = 0;
  REP(i, N) {
    for(int k = i + 1; k < N; ++k) {
      int right = lower_bound(L.begin(), L.end(), L[i] + L[k]) - L.begin();
      ans += max(right - (k + 1), 0);
    }
  }
  cout << ans << endl;
}