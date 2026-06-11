#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

const string YES = "Yes";
const string NO = "No";

void solve(string S) {
  bool pred = false;
  if (S.size() % 2 == 0) {
    pred = true;
    for (size_t i = 0; i < S.size(); i += 2) {
      if (S.substr(i, 2) != "hi") {
        pred = false;
        break;
      }
    }
  }
  cout << (pred ? YES : NO) << endl;
}

int main() {
  string S;
  cin >> S;
  solve(S);
  return 0;
}
