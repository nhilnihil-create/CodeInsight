#include <bits/stdc++.h>

#include <string>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  string n;
  cin >> n;
  long sum = 0;
  for (int i = 0; i < n.size(); i++) {
    sum += stol(to_string(n.at(i))) - 48;
  }
  if (sum % 9 == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
