#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  reverse(S.begin(), S.end());
  vector<int> T(N + 1);
  T.at(0) = 0;
  int k = 1;
  for (int i = 0; i < N; i++) {
    int x = S.at(i) - '0';
    T.at(i + 1) = (T.at(i) + x * k) % 2019;
    k = k * 10 % 2019;
  }
  vector<int> V(2019, 0);
  for (int i = 0; i <= N; i++) V.at(T.at(i))++;
  long long int ans = 0;
  for (int i = 0; i < 2019; i++) {
    if (V.at(i) > 1) ans += (V.at(i) - 1) * V.at(i) / 2;
  }
  cout << ans << endl;
}