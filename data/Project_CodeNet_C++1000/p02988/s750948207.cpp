#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> p(N);
  for (int i = 0; i < N; ++i) cin >> p[i], --p[i];
  int res = 0;
  for (int i = 1; i+1 < N; ++i) {
    vector<int> q = {p[i-1], p[i], p[i+1]};
    sort(q.begin(), q.end());
    if (p[i] == q[1]) ++res;
  }
  cout << res << endl;
}