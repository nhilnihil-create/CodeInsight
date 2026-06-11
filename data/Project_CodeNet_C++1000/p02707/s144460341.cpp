#include <bits/stdc++.h>
using namespace std;
int main()
  {int N; cin >> N;
  map<int, int> m;
  vector<int> A(N - 1); for (auto &a : A) {cin >> a; ++m[a];}
  for (int i = 1; i <= N; ++i) cout << m[i] << endl;}