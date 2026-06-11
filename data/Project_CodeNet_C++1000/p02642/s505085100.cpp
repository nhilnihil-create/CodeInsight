#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, ans{}; cin >> N;
  int A[N]; map<int, int>m; set<int> s; for (int &a: A) {cin >> a; ++m[a]; s.insert(a);}
  vector<bool> B(1000001, true); for (int a : s) for (int j{m[a] > 1 ? a : a + a}; j <= 1000000; j += a) B[j] = false;
  for (int a : A) ans += B[a]; cout << ans;}