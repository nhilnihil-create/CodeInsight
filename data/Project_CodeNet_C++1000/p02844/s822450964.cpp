#include <iostream>
#include <string>
#include <vector>
#include <set>

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

int main() {
  ll input(n);
  string input(s);
  vector<ll> si(n);
  REP(i, n) si[i] = s[i] - '0';

  int ans = 0;
  REP(i, 10) REP(j, 10) REP(k, 10) {
    int number = i * 100 + j * 10 + k;
    // int number = i + j * 10 + k * 100;
    int cnt = 0;
    for (auto v: si) {
      if (number % 10 == v) {
        number /= 10;
        cnt++;
      }
      if (cnt == 3) {
        ans++;
        break;
      }
    }
  }
  print(ans);
}
