#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long int64;
int MOD = 1e9 + 7;

map<int, int> kish;

int main() {
  int N, tmp;
  int64 ans = 1;
  cin >> N;
  kish[-1] = 3;
  rep(i, N) {
    cin >> tmp;
    ans *= kish[tmp - 1] - kish[tmp];
    ans %= MOD;
    ++kish[tmp];
  }
  cout << ans << "\n";
  return 0;
}
