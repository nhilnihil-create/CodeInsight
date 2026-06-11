#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  sort(A.begin(), A.end());
  A.erase(unique(A.begin(), A.end()), A.end());
  cout << ((N == A.size()) ? "YES" : "NO") << "\n";
}