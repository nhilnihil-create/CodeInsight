#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>

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

ll MOD = 1000000000 + 7;

int main() {
  ll input(n, k);
  vector<ll> a(n + 1);
  REP(i, n + 1) a[i] = i;
  vector<ll> cumsum(a.size() + 1, 0);
  partial_sum(a.begin(), a.end(), cumsum.begin() + 1);

  ll ans = 0;
  FOR(i, k, n + 1) {
    // print(cumsum[i], cumsum[n + 1] - cumsum[n + 1 - i]);
    (ans += (cumsum[n + 1] - cumsum[n + 1 - i]) - cumsum[i] + 1) %= MOD;
  }
  cout << ans << endl;
}
