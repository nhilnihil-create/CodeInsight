#include <bits/stdc++.h>
using namespace std;
int main()
  {int N, K, Q, A; cin >> N >> K >> Q;
  vector<int> P(N, K - Q); while (cin >> A) ++P[--A];
  for (int p : P) puts(p > 0 ? "Yes" : "No");}