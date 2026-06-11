#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> q(100001);
vector<vector<int>> tree(100001);
vector<set<int>> used(100001);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;

  cin >> N;
  for (int i = 0; i < N - 1; ++i) {
    int a, b;
    cin >> a >> b;
    pair<int, int> p = make_pair(a, b);
    q.at(i) = p;
    tree.at(a).push_back(b);
  }

  int max = 0;
  map<pair<int, int>, int> m;
  for (int i = 1; i <= N; ++i) {
    for (int j = 0; j < tree.at(i).size(); ++j) {
      int a = i;
      int b = tree.at(i).at(j);

      int t = 1;
      if (max == used.at(a).size() || max == used.at(b).size()) {
        t = max + 1;
      }
      while (true) {
        if (!used.at(a).count(t) && !used.at(b).count(t)) {
          used.at(a).insert(t);
          used.at(b).insert(t);
          if (used.at(a).size() > max) {
            max = used.at(a).size();
          }
          if (used.at(b).size() > max) {
            max = used.at(b).size();
          }
          break;
        }
        ++t;
      }
      m[make_pair(a, b)] = t;
    }
  }

  cout << max << endl;
  for (int i = 0; i < N - 1; ++i) {
    cout << m.at(q.at(i)) << endl;
  }
}
