#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

int main() {
  string T;
  cin >> T;
  for (auto &c: T) {
    if (c == '?') c = 'D';
  }
  cout << T << endl;
  return 0;
}
