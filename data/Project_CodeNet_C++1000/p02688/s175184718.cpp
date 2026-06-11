#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, K, d, A; cin >> N >> K;
  map<int, int> m; while (cin >> d) while (d--) cin >> A, m[A];
  cout << N - m.size();}