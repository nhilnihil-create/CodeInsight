#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> p(n);
  vector<int> q(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i];
    q[i] = p[i];
  }
  int ans = 0;
  sort(q.begin(), q.end());
  for (int i = 0; i < n; i++ ) {
    if (p[i] != q[i]) {
      ans++;
    }
  }
  cout << ((ans == 2 || ans == 0) ? "YES" : "NO") << endl;
}
