#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  string s, ans = "Yes";
  cin >> s;
  int n = s.size();
  if(n % 2 == 0) {
    for(int i = 0; i*2 < n; i++) {
      if (s.at(i*2) == 'L') ans = "No";
      if (s.at(i*2+1) == 'R') ans = "No";
    }
  }
  else {
    if (s.at(0) == 'L') ans = "No";
    for(int i = 0; i*2 < n-2; i++) {
      if (s.at(i*2+1) == 'R') ans = "No";
      if (s.at(i*2+2) == 'L') ans = "No";
    }
  }
  cout << ans << endl;
}
