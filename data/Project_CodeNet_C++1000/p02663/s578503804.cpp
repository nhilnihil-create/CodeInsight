#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int A, B, C, D, E;
  cin >> A >> B >> C >> D >> E;
  int T1, T2, TS;
  T1 = A * 60 + B;
  T2 = C * 60 + D;
  TS = T2 - T1;
  cout << TS - E << endl;
}
