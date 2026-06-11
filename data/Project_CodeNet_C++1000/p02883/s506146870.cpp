#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, K;
  cin >> N >> K;
  vector<long> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  vector<long> F(N);
  for (int i = 0; i < N; i++) cin >> F.at(i);
  sort(A.begin(), A.end());
  sort(F.rbegin(), F.rend());
  long ok = 1e18, ng = -1;
    while (ok - ng > 1) {
      long mid = (ok + ng) / 2;
      long sum = 0;
      for (int i = 0; i < N; i++) {
        if (A.at(i) * F.at(i) > mid) {
          long tmp = A.at(i) * F.at(i) - mid;
          sum += (tmp + F.at(i) - 1) / F.at(i);
        }
      }
      (sum <= K) ? ok = mid : ng = mid;
    }
  cout << ok << "\n";
}