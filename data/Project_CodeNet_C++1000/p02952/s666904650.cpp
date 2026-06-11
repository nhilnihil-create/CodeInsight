#include <bits/stdc++.h>
#define REP(i, n) for (long i = 0; i < n; ++i)
#define FOR(i, b, n) for (long i = b; i <= n; ++i)

using namespace std;

void solve(long N) {
  long ans(0);
  FOR(i, 1, N)
    if (to_string(i).length() % 2)
      ans++;
  cout << ans << endl;
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);

  long N;
  cin >> N;

  solve(N);

  return 0;
}
