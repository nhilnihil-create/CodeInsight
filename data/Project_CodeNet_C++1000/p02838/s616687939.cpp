#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M = 1e9+7;
  cin >> N;
  vector<long> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  vector<int> cnt(60);
  for (auto a : A) {
    int i = 0;
    while (a) cnt.at(i) += a % 2, a /= 2, i++;
  }
  long ans = 0;
  for (int i = 0; i < 60; i++) {
    ans += (1L << i) % M * cnt.at(i) % M * (N - cnt.at(i)) % M;
  }
  cout << ans % M << "\n";
}