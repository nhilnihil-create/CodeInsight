#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 6;
int gcd(int a, int b) {
  return (b ? gcd(b, a % b) : a);
}
int main() {
  int n;
  cin >> n;
  vector<int> del(N);
  for (int i = 2; i < N; ++i) {
    if (!del[i])
      for (int j = i; j < N; j += i)
        del[j] = i;
  }
  vector<int> kek(n);
  set<int> st;
  bool ok = true;
  for (int i = 0; i < n; ++i) {
    cin >> kek[i];
    int vl = kek[i];
    while (vl > 1) {
      int lol = del[vl];
      while (vl > 1 && del[vl] == lol)
        vl /= lol;
      if (st.find(lol) != st.end())
        ok = false;
      st.insert(lol);
    }
  }
  if (ok) {
    cout << "pairwise coprime";
    return 0;
  }
  int gg = kek[0];
  for (int i = 1; i < n; ++i)
    gg = gcd(gg, kek[i]);
  if (gg == 1)
    cout << "setwise coprime";
  else
    cout << "not coprime";
}