#include <bits/stdc++.h>
using namespace std;
int main()
  {int N; cin >> N;
  vector<int64_t> A(N); for (auto &a : A) cin >> a;
  auto ans = 0LL;
  for (int k = 0; k < 60; ++k)
    {auto z = 0LL; for (auto a : A) if (!(a >> k & 1)) ++z;
    auto s = z * (N - z);
    if (s) for (int i = 0; i < k; ++i) s = s * 2 % 1000000007;
    ans = (ans + s) % 1000000007;}
  cout << ans << endl;}