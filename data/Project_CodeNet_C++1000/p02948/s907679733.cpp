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

ll n, m;
vector<pair<ll, ll>> ab;

int main() {
  cin >> n >> m;
  ab = vector<pair<ll, ll>>(n);
  REP(i, n) {
    ll input(a, b);
    ab[i] = {a, b};
  }

  sort(ab.begin(), ab.end(), [](auto v1, auto v2){
      return v1.second > v2.second;
  });

  // sort(ab.begin(), ab.end(), [](auto v1, auto v2){
  //     if (v1.first == v2.first) {
  //       return v1.second > v2.second;
  //     }
  //     return v1.first > v2.first;
  // });

  vector<ll> plan(m + 1, 0);
  vector<ll> shift(m + 1);
  REP(i, n) {
    if (ab[i].first > m) continue;
    if (plan[ab[i].first] == 0) {
      plan[ab[i].first] = ab[i].second;
      shift[ab[i].first] = ab[i].first + 1;
    } else {
      vector<ll> visited;
      for (ll nxt = shift[ab[i].first];; nxt = shift[nxt]) {
        if (nxt > m) break;

        visited.push_back(nxt);
        if (plan[nxt] == 0) {
          for (auto v: visited) {
            shift[v] = nxt + 1;
          }
          plan[nxt] = ab[i].second;
          break;
        }
      }
    }
  }
  cout << accumulate(plan.begin(), plan.end(), 0ll) << endl;
}
