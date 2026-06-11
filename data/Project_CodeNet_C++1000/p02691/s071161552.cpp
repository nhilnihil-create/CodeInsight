#include <bits/stdc++.h>
using namespace std;
int main()
  {int N; cin >> N;
  map<int, int> m;
  vector<int> A(N + 1); for (int i = 1; i <= N; ++i) {cin >> A[i]; ++m[i - A[i]];}
  auto ans = 0LL; for (int i = 1; i <= N; ++i) ans += m[i + A[i]];
  cout << ans << endl;}