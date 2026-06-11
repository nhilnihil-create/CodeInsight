#include <bits/stdc++.h>
using namespace std;

int main() {
  int K, N;
  cin >> K >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  int mx = A.at(0) + (K - A.at(N - 1));
  for (int i = 1; i < N; i++) {
    mx = max(mx, A.at(i) - A.at(i - 1));
  }
  cout << K - mx << "\n";
}