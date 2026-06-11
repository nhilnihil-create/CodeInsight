#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, m(1e7), W; cin >> N;
  vector<int> S(N + 1); for (int i{}; i < N; ++i) cin >> W, S[i + 1] = S[i] + W;
  for (int T{1}; T < N; ++T) m = min(m, abs(2 * S[T] - S[N]));
  cout << m;}