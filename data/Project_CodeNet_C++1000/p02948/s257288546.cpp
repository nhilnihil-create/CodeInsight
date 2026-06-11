#include <bits/stdc++.h>
using namespace std;

int main() {

  int N, M;
  cin >> N >> M;

  vector<vector<int>> v(M);
  for (int i = 0; i < N; i++) {
    int A, B;
    cin >> A >> B;
    if (M < A) {
      continue;
    }
    v[M - A].push_back(B);
  }

  priority_queue<int> q;
  long long ans = 0;

  for (int i = M - 1; 0 <= i; i--) {
    for (int j = 0; j < v[i].size(); j++) {
      q.push(v[i][j]);
    }
    if (!q.empty()){
      ans += q.top();
      q.pop();
    }
  }

  cout << ans << endl;
  return 0;

}