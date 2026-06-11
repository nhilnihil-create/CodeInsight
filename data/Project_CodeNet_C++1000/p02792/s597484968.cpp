#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<vector<int> > v(10, vector<int>(10, 0));
  for (int a = 1; a <= n; ++a) {
    string s = to_string(a);
    int i = s.front() - '0';
    int j = s.back() - '0';
    ++v[i][j];
  }

  long long ans = 0;
  for (int a = 1; a <= n; ++a) {
    string s = to_string(a);
    int i = s.front() - '0';
    int j = s.back() - '0';
    ans += v[j][i];
  }
  cout << ans << endl;

  return 0;
}
