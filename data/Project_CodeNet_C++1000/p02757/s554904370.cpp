#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, P;
  string S;
  cin >> N >> P >> S;
  reverse(S.begin(), S.end());
  
  if (10 % P == 0) {
    long ans = 0;
    for (int i = 0; i < N; i++) {
      if ((S.at(i) - '0') % P == 0) ans += N - i;
    }
    return cout << ans << "\n", 0;
  }
  
  int dig = 1, sum = 0;
  map<int, int> MA;
  MA[0]++;
  for (int i = 0; i < N; i++) {
    (sum += (S.at(i) - '0') * dig) %= P;
    (dig *= 10) %= P;
    MA[sum]++;
  }
  long ans = 0;
  for (auto ma : MA) ans += (long) ma.second * (ma.second - 1) / 2;
  cout << ans << "\n";
}