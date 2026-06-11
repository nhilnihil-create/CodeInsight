#include <bits/stdc++.h>
#define REP(i, n) for (long i = 0; i < n; ++i)

using namespace std;
using ll = long long;

void solve(long N, long K, int R, int S, int P, string T) {

  long ans(0);
  REP(i, N) {
    char t = T[i];

    if (i >= K && T[i-K] == t) {
      T[i] = 'X';
      continue;
    }
      
    switch (t) {
    case 'r':
      ans += P;
      break;
    case 's':
      ans += R;
      break;
    case 'p':
      ans += S;
      break;
    }
  }
  cout << ans << endl;
}

int main(){
  // int 3E4  long 2E9  ll 9E18
  cin.tie(0);
  ios::sync_with_stdio(false);

  long N, K;
  int R, S, P;
  cin >> N >> K >> R >> S >> P;
  string T;
  cin >> T;
  solve(N, K, R, S, P, T);
  return 0;
}
