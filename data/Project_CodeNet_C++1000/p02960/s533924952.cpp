#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <numeric>

using namespace std;

using ll = long long;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

#define input(...) __VA_ARGS__; in(__VA_ARGS__)

#if __has_include("debugger.cpp")
  #include "debugger.cpp"
#else
void print() {
  std::cout << std::endl;
}

template <class Head, class... Tail>
void print(Head&& head, Tail&&... tail) {
  cout << head;
  if (sizeof...(tail) > 0) cout << " ";
  print(std::forward<Tail>(tail)...);
}
# endif

void in() { }

template <class Head, class... Tail>
void in(Head&& head, Tail&&... tail) {
  cin >> head;
  in(std::forward<Tail>(tail)...);
}

ll toi(char x) {
  return x - '0';
}

vector<ll> d;
string s;
ll MOD = 1000000000 + 7;
vector<vector<ll>> table;

ll dp(ll i, ll v);
#define DP table[i][v]
ll dfs(ll i, ll v) {
  if (DP != -1) return DP;
  else return DP = dp(i, v);
}
ll dp(ll i, ll v) {
  if (i == s.size()) return v == 5;
  if (s[i] == '?') {
    ll ans = 0;
    REP(j, 10) {
      (ans += dfs(i + 1, (j * d[i] % 13 + v) % 13)) %= MOD;
    }
    return ans;
  } else {
    return dfs(i + 1, (toi(s[i]) * d[i] % 13 + v) % 13);
  }
}

int main() {
  cin >> s;
  s = string(s.rbegin(), s.rend());
  d = vector<ll>(s.size());
  d[0] = 1;
  REP(i, s.size() - 1) {
    d[i + 1] = (d[i] * 10) % 13;
  }
  table = vector<vector<ll>>(s.size() + 1, vector<ll>(13, -1));

  print(dfs(0, 0));
}
