#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

using ll = long long;

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
string s;
vector<vector<ll>> score;

#define DP score[i][type]
ll dfs(ll i, ll type) {
  if (DP != -1) return DP;
  if (i == s.size() + 1) return DP = -(1ll << 60);
  if (i == s.size()) return DP = 0;
  if (type == 1) {
    return DP = dfs(i + 1, 0) + 1;
  } else {
    if (s[i - 1] != s[i]) {
      return DP = max(dfs(i + 1, 0) + 1, dfs(i + 2, 1) + 1);
    } else {
      return DP = dfs(i + 2, 1) + 1;
    }
  }
}

int main() {
  cin >> s;
  s = "@" + s;
  score = vector<vector<ll>>(s.size() + 2, vector<ll>(2, -1));

  cout << dfs(1, 0);
}
