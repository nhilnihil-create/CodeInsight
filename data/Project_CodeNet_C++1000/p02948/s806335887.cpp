#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;
int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> a(max(n, m) + 10, {1000000, 0});
  for(int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
  }
  auto compare = [](auto const &l, auto const &r) {
    if(l.first != r.first) {
      return l.first < r.first;
    } else if(l.second != r.second) {
      return l.second > r.second;
    } else {
      return false;
    }
  };
  sort(a.begin(), a.end(), compare);

  auto compare2 = [](auto l, auto r) { 
    return l.second < r.second; 
  };
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(compare2)> que{compare2};
  ll ans = 0;
  auto itr = a.begin();
  for(int i = 0; i < m; i++) {
    while(itr != a.end() && (*itr).first < i + 2) {
      que.push(*itr);
      itr++;
    }
    if(que.empty()) {
      continue;
    }
    ans += que.top().second;
    que.pop();
  }
  cout << ans << endl;
  return 0;
}