#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, N;
  cin >> H >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  long acc = accumulate(A.begin(), A.end(), 0L);
  cout << ((H <= acc) ? "Yes" : "No") << "\n";
}