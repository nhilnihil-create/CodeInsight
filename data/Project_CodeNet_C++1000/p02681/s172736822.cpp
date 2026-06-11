#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  string s, t;

  cin >> s >> t;

  /* if (s.size() >= 1 && s.size() <= 10 && t.size() == s.size() + 1 && */
  /*     t.find(s) == t.at(0)) { */
  /*   cout << "Yes" << endl; */
  /* } else { */
  /*   cout << "No" << endl; */
  /* } */
  if (s.size() + 1 != t.size()) {
    cout << "No" << endl;
    return 0;
  }

  for (long i = 0; i < s.size(); i++) {
    if (s.at(i) != t.at(i)) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}
