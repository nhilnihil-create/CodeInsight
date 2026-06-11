#include <bits/stdc++.h>
using namespace std;
int n;
int cost(int i, int j, vector<vector<int>> &C, const vector<int> &p) {
  int min_cost = INT_MAX;
  if (C[i][j] != 0) return C[i][j];
  if (i == j) {
    min_cost = 0;
  } else if (i + 1 == j) {
    min_cost = p[i - 1] * p[i] * p[i + 1];
  } else {
    for (int k = j - 1; i < k; k--) {
      min_cost =
          min(cost(i, k, C, p) + cost(k + 1, j, C, p) + p[i - 1] * p[k] * p[j],
              min_cost);
    }
    C[i][j] = min_cost;
  }
  return min_cost;
}
int main() {
  int tmp;
  cin >> n;
  vector<int> p(n + 1);
  vector<vector<int>> C(n + 1, vector<int>(n + 1, 0));
  cin >> p[0];
  for (size_t i = 1; i <= n; i++) {
    cin >> p[i] >> tmp;
  }

  cout << cost(1, n, C, p) << endl;
}

