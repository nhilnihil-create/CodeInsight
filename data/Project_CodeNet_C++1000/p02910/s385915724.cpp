#include <bits/stdc++.h>
using namespace std;

int main() {
  string s, ans = "Yes";
  cin >> s;
  int N = s.size();
  
  for (int i = 0; i < N; i++) {
    if (i%2 == 0) {
      if (s[i] == 'L') ans = "No";
    } else {
      if (s[i] == 'R') ans = "No";
    }
  }
  
  cout << ans << endl;;
}