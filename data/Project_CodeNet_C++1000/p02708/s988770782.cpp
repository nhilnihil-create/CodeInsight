#include <bits/stdc++.h>
using namespace std;
int main()
  {int64_t N, K, ans{}; cin >> N >> K;
  for (auto i{K}; i <= N + 1; ++i) ans = (ans + i * (N - i + 1) + 1) % 1000000007;
  cout << ans;}