#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) for (int i = (0); i < (n); ++i)
#define ALL(obj) (obj).begin(), (obj).end()
#define DEBUG(val) cout << #val << " : " << val << endl
#define MOD 1000000007

int main() {
  int n;
  cin >> n;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      data;
  REP(i, n) {
    int x, y;
    cin >> x >> y;
    data.push(make_pair(x - y, x + y));
  }
  int ans = 0;

  while (data.size() > 1) {
    pair<int, int> p1 = data.top();
    data.pop();
    pair<int, int> p2 = data.top();
    data.pop();
    if (p2.first < p1.second) {
      if (p2.second <= p1.second) {
        data.push(p2);
        ans++;
      } else {
        data.push(p1);
        ans++;
      }
    } else {
      data.push(p2);
      continue;
    }
  }
  cout << n - ans << endl;
}