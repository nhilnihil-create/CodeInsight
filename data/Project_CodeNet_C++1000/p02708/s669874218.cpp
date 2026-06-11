#include <iostream>
#include <string>
#include <vector>

using namespace std;

using ll = long long;

template <class T>
using grid = vector<vector<T>>;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)

#define input(...) __VA_ARGS__; in(__VA_ARGS__)

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

ll sum(ll right) {
  return right * (right + 1) / 2;
}

ll sum(ll left, ll right) {
  return sum(right) - sum(left - 1);
}

ll MOD = 1000000000 + 7;

int main() {
  ll input(n, k);
  ll ans = 0;
  FOR(i, k, n + 1) {
    (ans += sum(n - (i - 1), n) - sum(i - 1) + 1) %= MOD;
  }
  print(ans);
}