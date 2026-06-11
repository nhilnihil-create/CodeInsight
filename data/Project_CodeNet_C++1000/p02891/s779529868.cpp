#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  long K;
  cin >> S >> K;

  string T = S + ' ';
  int t = 0;
  for (int i = 0, cnt = 1; i + 1 < T.size(); i++) {
    if (T.at(i) != T.at(i + 1)) t += cnt / 2, cnt = 1;
    else cnt++;
    if (cnt == S.size()) return cout << cnt * K / 2 << "\n", 0;
  }

  string R = S + S + ' ';
  int r = 0;
  for (int i = 0, cnt = 1; i + 1 < R.size(); i++) {
    if (R.at(i) != R.at(i + 1)) r += cnt / 2, cnt = 1;
    else cnt++;
  }

  cout << ((K == 1) ? t : t + (r - t) * (K - 1)) << "\n";
}