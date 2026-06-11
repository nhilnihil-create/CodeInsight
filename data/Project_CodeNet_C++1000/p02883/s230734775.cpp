#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, K;
  cin >> N >> K;
  vector<long> A(N), F(N);
  for (long i = 0; i < N; i++) cin >> A.at(i);
  for (long i = 0; i < N; i++) cin >> F.at(i);
  sort(A.begin(), A.end());
  sort(F.rbegin(), F.rend());
  vector<long> V(N);
  for (int i = 0; i < N; i++) V.at(i) = A.at(i) * F.at(i);
  long L = -1, R = 2e18;
    while (R - L > 1) {
      long M = (L + R) / 2;
      long sum = 0;
      for (long i = 0; i < N; i++) {
        if (V.at(i) > M) sum += ((V.at(i) - M) + F.at(i) - 1) / F.at(i);
      }
      (sum <= K) ? R = M : L = M;
    }
  cout << R << "\n";
}
