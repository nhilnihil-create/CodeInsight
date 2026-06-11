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

int main() {
  ll input(n);
  vector<ll> a(n + 1), b(n);
  REP(i, n + 1) cin >> a[i];
  REP(i, n) cin >> b[i];
  ll cnt = 0;
  REP(i, n) {
    if (a[i] > b[i]) cnt += b[i];
    else {
      cnt += a[i];
      ll diff = b[i] - a[i];
      cnt += diff;
      a[i + 1] -= diff;

      if (a[i + 1] < 0) {
        cnt += a[i + 1];
        a[i + 1] = 0;
      }
    }
  }
  print(cnt);
}
