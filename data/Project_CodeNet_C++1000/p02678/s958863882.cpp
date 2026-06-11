#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

vector<vector<ll>> g;

vector<bool> seen;
vector<ll> ans;
const long long NIL = -1;
deque<ll> todo;

int main() {
  ll n, m;
  cin >> n >> m;
  g.resize(n);
  seen.resize(n);

  ans.resize(n, NIL);

  for (long long i = 0; i < m; i++) {
    ll a, b;
    cin >> a >> b;
    a--;
    b--;

    g.at(a).push_back(b);
    g.at(b).push_back(a);
  }

  todo.push_back(0);
  while (!todo.empty()) {
    ll v = todo.front();
    todo.pop_front();

    if (seen.at(v)) {
      continue;
    }

    for (auto x : g.at(v)) {
      if (ans.at(x) == NIL) {
        ans.at(x) = v + 1;
        todo.push_back(x);
      }
    }
  }

  if (find(seen.begin(), seen.end(), false) == seen.end()) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  for (long long i = 1; i < n; i++) {
    cout << ans.at(i) << endl;
  }
}
