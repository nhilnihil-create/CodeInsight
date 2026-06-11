#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

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

int main() {
  double input(a, b, x);
  double xd = x / (a*a);
  cout << setprecision(10);
  if (xd <= b / 2) {
    cout << (atan(b * b / (2 * a * xd)) * (180 / M_PI));
  } else {
    cout << (atan((b - xd) / (a / 2)) * (180 / M_PI));
  }
  cout << endl;
}
