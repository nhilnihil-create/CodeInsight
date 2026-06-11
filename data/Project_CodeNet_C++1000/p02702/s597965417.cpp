#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <numeric>
#include <limits>
#include <algorithm>
#include <functional>
#include <map>

using namespace std;

using ll = long long;

template <class T>
using grid = vector<vector<T>>;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

#define input(...) __VA_ARGS__; in(__VA_ARGS__)

template<class T>
void print(vector<T> a) {
  cout << "[ ";
  REP(i, a.size()) cout << a[i] << " ";
  cout << "]" << endl;
}

void print() {
  std::cout << std::endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  std::cout << head << " ";
  print(std::forward<Tail>(tail)...);
}

void in() { }

template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
  cin >> head;
  in(std::forward<Tail>(tail)...);
}

// vector<int> d;
// ll dp(int i, int m) {
//   if (i == d.size()) {
//     return 0;
//   }
//   int value = (m * 10 + d[i]) % 2019;
//   return dp(i + 1, value) + (value == 0);
// }

int main() {
  string input(s);
  int n = s.size();
  vector<int> d(n);
  REP(i, n) d[n - i - 1] = s[i] - '0';

  vector<int> p(n);
  ll m = 1;
  ll pp = 0;
  REP(i, n) {
    p[i] = pp = (m * d[i] + pp) % 2019;
    (m *= 10) %= 2019;
  }

  map<int, int> cnt;
  for (auto v: p) {
    cnt[v] += 1;
  }

  ll ans = 0;
  for (auto v: cnt) {
    if (v.first == 0) ans += v.second;
    if (v.second >= 2) {
      ans += (v.second * (v.second - 1)) / 2;
    }
  }
  print(ans);
}
