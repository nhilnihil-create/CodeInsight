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

  int count = 0;
  for (long i = 0; i < n - 2; i++) {
    if (s.at(i) == 'A' && s.at(i + 1) == 'B' && s.at(i + 2) == 'C') {
      count++;
    }
  }

  cout << count << endl;
}
