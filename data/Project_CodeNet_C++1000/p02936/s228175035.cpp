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

vector<vector<ll>> graph;
vector<ll> cnt;

void dfs(ll node, ll parent, ll sum) {
  for(ll n: graph[node]) {
    if (n != parent) dfs(n, node, sum + cnt[n]);
  }
  cnt[node] = sum;
}

int main() {
  ll input(n, q);
  graph = vector<vector<ll>>(n);
  REP(i, n - 1) {
    ll input(a, b);
    graph[a - 1].push_back(b - 1);
    graph[b - 1].push_back(a - 1);
  }

  cnt = vector<ll>(n);
  REP(i, q) {
    ll input(p, x);
    cnt[p - 1] += x;
  }

  dfs(0, -1, cnt[0]);
  REP(i, n - 1) {
    cout << cnt[i] << " ";
  }
  cout << cnt[n - 1] << endl;
}
