#include <bits/stdc++.h>
using namespace std;

int n, m, q;
vector<long long> a, b, c, d;
long long answer = 0;

long long ans(vector<int> A) {
  long long res = 0;
  for (int i = 0; i < q; i++) {
    if (A[b[i]] - A[a[i]] == c[i]) {
      res += d[i];
    }
  }

  return res;
}

long long dfs(vector<int> &A) {
  if ((int)A.size() == n) {
    ans(A);
    return ans(A);
  }
  long long res = 0;
  int pre_value = (A.empty() ? 0 : A.back());

  for (int i = pre_value; i < m; i++) {
    A.push_back(i);
    res = max(res, dfs(A));
    A.pop_back();
  }
  return res;
}
int main() {
  cin >> n >> m >> q;
  a.resize(q);
  b.resize(q);
  c.resize(q);
  d.resize(q);
  for (int i = 0; i < q; i++) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    --a[i];
    --b[i];
  }
  vector<int> A;

  cout << dfs(A) << endl;

  return 0;
}