#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, P;
  string S;
  cin >> N >> P >> S;
  reverse(S.begin(), S.end());

  if (10 % P == 0) {
    long ans = 0;
    for (long i = 0; i < N; i++) {
      if ((S.at(i) - '0') % P == 0) ans += N - i;
    }
    return cout << ans << "\n", 0;
  }

  vector<long> V(P);
  long sum = 0;
  V.at(sum)++;
  for (long i = 0, dig = 1; i < N; i++, dig = dig * 10 % P) {
    sum += (S.at(i) - '0') * dig;
    sum %= P;
    V.at(sum)++;
  }
  long ans = 0;
  for (auto v : V) ans += v * (v - 1) / 2;
  cout << ans << "\n";
}