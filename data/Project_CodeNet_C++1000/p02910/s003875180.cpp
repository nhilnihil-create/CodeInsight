#include <iostream>

using namespace std;
using ll = long long;
using ld = long double;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

const string YES = "Yes";
const string NO = "No";

void solve(string S) {
  bool pred = true;

  for (size_t i = 0; i != S.size(); ++i) {
    if ((i%2 && S[i] == 'R') || (i%2==0 && S[i] == 'L')) {
      pred = false;
      break;
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
