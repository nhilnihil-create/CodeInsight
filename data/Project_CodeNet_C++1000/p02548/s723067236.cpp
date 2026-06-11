#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define REP(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
#define ALL(x) ((x).begin()), ((x).end())

#define READ(x) (cin >> (x))
#define WRITE_N(x) (cout << (x) << endl)
#define WRITE(x) (cout << (x))
#define WRITE_YESNO(x) (WRITE_N((x) ? "Yes" : "No"))

#define PRECISE_COUT std::cout << std::setprecision(15) << std::fixed

bool xor_logic(bool x, bool y) { return (x && y) || (!x && !y); }

int solve(int N) {
  int retv = 0;
  for (int A = 1; A < N; A++) {
    retv += (N - 1) / A;
  }

  return retv;
}

int main() {
  // get values from input
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N;
  cin >> N;

  // main procedure
  int ans = solve(N);

  // output
  cout << ans << endl;

  return 0;
}