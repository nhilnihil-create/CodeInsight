#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<string> s(N);
  vector<int> t(N);
  for (int i = 0; i < N; i++) cin >> s.at(i) >> t.at(i);
  string X; cin >> X;

  int ans = 0;
  bool flag = false;
  for (int i = 0; i < N; i++) {
    if (flag) ans += t.at(i);
    if (s.at(i) == X) flag = true;
  }
  cout << ans << endl;
}