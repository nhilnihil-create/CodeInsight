#include <bits/stdc++.h>
using namespace std;
int main()
  {int X, Y, A, B, C, r; cin >> X >> Y >> A >> B >> C;
  vector<int> P(A), Q(B), xs; for (int &p : P) cin >> p; for (int &q : Q) cin >> q; sort(rbegin(P), rend(P)); sort(rbegin(Q), rend(Q));
  for (int i{}; i < X; ++i) xs.push_back(P[i]); for (int i{}; i < Y; ++i) xs.push_back(Q[i]);
  while (C--) {cin >> r; xs.push_back(r);} sort(rbegin(xs), rend(xs));
  cout << accumulate(begin(xs), begin(xs) + X + Y, 0LL);}