#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  long n;
  cin >> n;

  string s;
  cin >> s;
  string s1 = s.substr(0, n / 2);
  string s2 = s.substr(n / 2);
  if (s1 == s2) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
