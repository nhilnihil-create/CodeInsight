// #include <bits/stdc++.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <map>
#include <math.h>
#include <algorithm> // std::sort, std::min, std::next_permutation, std::lower_bound
#include <iomanip> // std::setprecision
#include <cmath> // std::ceil
#include <numeric> // std::gcd, std::lcm
#include <limits> // std::numeric_limits<long int>::max()
#include <unordered_map>
#include <map>
#include <cmath> // std::atan2
#include <deque>
#include <queue>
#include <bitset>
#include <functional>
#include <cassert>

using namespace std;
typedef long long ll;
#define INF 1999999999
#define MODA 1000000007 
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename T = long long, typename T2 = long long>
std::vector<std::vector<T>> convert_rooted_tree(const std::vector<std::vector<T>> &tree, T2 root = 0) {
  T N = tree.size();
  std::vector<std::vector<T>> rooted_tree(N);
  vector<bool> foundflag(N);
  foundflag[root] = true;
  queue<T> que;
  que.emplace(root);
  while(!que.empty()) {
    auto p = que.front();
    que.pop();
    for(auto &to : tree[p]) { 
      // The case using vector<vector<pair<ll, ll> > > as tree 
      // (ex, need to set the cost of links to pair.second),
      // replace index of foundflag and que from to -> to.first
      if(foundflag[to] == false) {
        foundflag[to] = true;
        que.emplace(to);
        rooted_tree[p].emplace_back(to);
      }
    }
  }
  return rooted_tree;
}

vector<vector<ll>> rtree;
vector<ll> counter;

void sumup(ll ind, ll cursum) {
  counter[ind] += cursum;
  for (auto node : rtree[ind]) {
    sumup(node, counter[ind]);
  }
}

int main() {
  ll N, Q;
  cin >> N >> Q;
  vector<ll> a(N), b(N);
  for(ll i=1; i < N; ++i) cin >> a[i] >> b[i];
  vector<ll> p(Q), x(Q);
  rep(i, Q) cin >> p[i] >> x[i];

  vector<vector<ll> > tree(N+1);
  for (ll i = 1; i < N+1; ++i) {
    tree[a[i]].emplace_back(b[i]);
    tree[b[i]].emplace_back(a[i]);
  }
  // vector<vector<ll>> rtree = convert_rooted_tree(tree, static_cast<ll>(1));
  rtree = convert_rooted_tree(tree, 1);
  counter.resize(N+1, 0);
  rep(i, Q) {
    counter[p[i]] += x[i];
  }
  sumup(1, 0);
  for (ll i = 1; i < counter.size(); ++i) {
    cout << counter[i] <<" ";
  }
  return 0;
}
