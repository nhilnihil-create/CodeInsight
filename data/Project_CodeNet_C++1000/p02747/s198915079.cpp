#include <bits/stdc++.h>
using namespace std;
char s[101010];
int main() {
  cin >> s;
  int n = strlen(s);
  if (n % 2) {
    cout << "No";
    return 0;
  }
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    ok &= i % 2 ? s[i] == 'i' : s[i] == 'h';
  }
  cout << (ok ? "Yes" : "No");
  return 0;
}