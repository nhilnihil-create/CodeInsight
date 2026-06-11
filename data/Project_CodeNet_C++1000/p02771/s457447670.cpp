#include <bits/stdc++.h>
using namespace std;

int main() {
  int N = 3;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  sort(A.begin(), A.end());
  A.erase(unique(A.begin(), A.end()), A.end());
  cout << ((A.size() == 2) ? "Yes" : "No") << "\n";
}