#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  map<int, int> cnt;
  long long res = 0;
  for (int i = 1; i <= n; i++) {
    int foo;
    cin >> foo;
    res += cnt [ -foo + i ];
    cnt[ foo + i ]++;
  }
  cout << res << '\n';
  return 0;
}
