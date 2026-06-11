#include <bits/stdc++.h>
using namespace std;
int main()
  {int X, Y, A, B, C; cin >> X >> Y >> A >> B >> C;
  vector<int> ps(A), qs(B), rs(C), as; for (auto xs : {&ps, &qs, &rs}) {for (auto &b: *xs) cin >> b; sort((*xs).rbegin(), (*xs).rend());}
  for (int i = 0; i < X; ++i) as.push_back(ps[i]);
  for (int i = 0; i < Y; ++i) as.push_back(qs[i]);
  for (auto r : rs) as.push_back(r);
  sort(as.rbegin(), as.rend());
  auto ans = 0LL; for (int i = 0; i < X + Y; ++i) ans += as[i];
  cout << ans << endl;}