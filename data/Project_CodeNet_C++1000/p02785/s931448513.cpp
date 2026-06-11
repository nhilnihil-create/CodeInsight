#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> H(N);
  for (int i = 0; i < N; i++) cin >> H.at(i);
  sort(H.rbegin(), H.rend());
  K = min(N, K);
  cout << accumulate(H.begin() + K, H.end(), 0L) << "\n";
}