#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;

ll n, m, q;
vector<long long> a, b, c, d;

int score(const vector<int> &A) {
  ll res = 0;
  for (int i = 0; i < q; i++) {
    if (A[b[i]] - A[a[i]] == c[i]) {
      res += d[i];
    }
  }

  return res;
}

ll dfs(vector<int> &A) {
  if (A.size() == n) {
    return score(A);
  }

  ll res = 0;
  int prev_last = (A.empty() ? 0 : A.back());
  for (int v = prev_last; v < m; v++) {
    A.push_back(v);
    res = max(res, dfs(A));
    A.pop_back();
  }

  return res;
}

int main() {
  cin >> n >> m >> q;

  a.resize(q); b.resize(q); c.resize(q); d.resize(q);
  for (int i = 0; i < q; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--, b[i]--;
  }

  vector<int> A;
  cout << dfs(A) << endl;

  return 0;
}