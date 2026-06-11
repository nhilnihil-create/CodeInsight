#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5 + 5;
int n, m, t;
auto cmp = [](ii a, ii b) {
  return a.first / pow(2, a.second) < b.first / pow(2, b.second);
};
priority_queue<ii, vector<ii>, decltype(cmp)> pq(cmp);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    cin >> t;
    pq.push({t, 0});
  }
  while (m) {
    auto a = pq.top();
    pq.pop();
    ++a.second;
    m--;
    pq.push(a);
  }
  ll res = 0;
  while (!pq.empty()) {
    auto p = pq.top();
    pq.pop();
    res += p.first / (int)pow(2, p.second);
  }
  cout << res << endl;
  
  return 0;
}
