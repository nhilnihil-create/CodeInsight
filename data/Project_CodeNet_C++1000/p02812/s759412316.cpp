#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  string s; cin >> s;

  int ans = 0;
  for(int i = 0; i < n - 2; i++) {
    string substring = s.substr(i, 3);
    if(substring.compare("ABC") == 0) ans ++;
  }
  cout << ans << endl;
  return 0;
}
