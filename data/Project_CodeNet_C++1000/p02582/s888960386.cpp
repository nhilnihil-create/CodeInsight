#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  string s;
  cin >> s;
  int ans = 0;
  if (s.find("RRR") == 0) {
    ans = 3;
  } else if (s.find("RR") == 0 || s.find("RR") == 1) {
    ans = 2;
  } else if (s.find("R") <= 2) {
    ans = 1;
  } else {
    ans = 0;
  }
  cout << ans << endl;
}
