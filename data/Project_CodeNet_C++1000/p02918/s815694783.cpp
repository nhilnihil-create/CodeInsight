#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < n - 1; ++i) {
    cnt += s[i] == s[i + 1];
  }
  cout << min(cnt + 2 * k, n - 1) << endl;
}
