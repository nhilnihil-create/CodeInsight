#include <iostream>
#include <string>

using namespace std;
using ll = long long;

#define ALL(x) begin(x), end(x)
#define REP(i, n) for (size_t i = 0, i##_len = (n); i < i##_len; ++i)

void solve(ll S) {
  string str = to_string(S);
  bool pred = true;
  for (auto i = 0; i != 3; ++i) {
    if (str[i] == str[i + 1]) pred = false;
  }
  cout << (pred ? "Good" : "Bad") << endl;
}

int main() {
  ll S;
  cin >> S;
  solve(S);
  return 0;
}
