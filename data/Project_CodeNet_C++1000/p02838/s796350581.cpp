#include <bits/stdc++.h>
using namespace std;
int64_t M = 1e9 + 7;
int main()
  {int N; cin >> N;
  vector<int64_t> A(N); for (auto &a : A) cin >> a;
  auto ans = 0LL, p = 1LL;
  for (int k = 0; k < 60; ++k)
    {auto z = 0LL; for (auto a : A) if (!(a >> k & 1)) ++z;
    ans = (ans + z * (N - z) % M * p % M) % M;
    p = p * 2 % M;}
  cout << ans << endl;}