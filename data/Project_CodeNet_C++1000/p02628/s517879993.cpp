#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)                    \
  for (int i = 0; i < (int)(n); i++) \
    ;

#define _GLIBCXX_DEBUG
#define _LIBCPP_DEBUG 0

int main() {
  long n, k;
  cin >> n >> k;

  vector<long> p(n);
  for (long &x : p) {
    cin >> x;
  }

  sort(p.begin(), p.end());
  vector<long> csump(p.size() + 1, 0);
  for (int i = 1; i <= p.size(); i++) {
    csump.at(i) = csump.at(i - 1) + p.at(i - 1);
  }

  cout << csump.at(k) << endl;
}
