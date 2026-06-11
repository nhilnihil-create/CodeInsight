#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N;
  string S, T;
  cin >> N >> S >> T;

  string res(N * 2, 'a');
  rep(i, N) {
    res[i * 2] = S[i];
    res[i * 2 + 1] = T[i];
  }

  cout << res << endl;

  return 0;
}
