#include <queue>
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
  ll input(n, x, y);
  vector<vector<ll>> graph(n);
  REP(i, n - 1) {
    graph[i].push_back(i + 1);
    graph[i + 1].push_back(i);
  }
  graph[x - 1].push_back(y - 1);
  graph[y - 1].push_back(x - 1);

  struct Args {
    ll to, cost;
  };
  vector<vector<ll>> visited(n, vector<ll>(n, -1));
  // auto comp = [](Args &v1, Args &v2){
  //   return v1.cost > v2.cost;
  // };
  REP(i, n) {
    // priority_queue<Args, vector<Args>, decltype(comp)> que{comp};
    queue<Args> que;
    que.push({i, 0});
    while(!que.empty()) {
      Args args = que.front();
      // Args args = que.top();
      que.pop();
      if (visited[i][args.to] != -1) continue;

      visited[i][args.to] = args.cost;
      for(auto v: graph[args.to]) {
        que.push({v, args.cost + 1});
      }
    }
  }

  // print(visited);
  map<ll, ll> cnt;
  for(auto v: visited) {
    for(auto value: v) {
      cnt[value]++;
    }
  }

  REP(i, n - 1) {
    print(cnt[i + 1] / 2);
  }
}
