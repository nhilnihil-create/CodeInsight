#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    B.at(i) = A.at(i);
  }
  sort(B.begin(), B.end());
  for (int i = 0; i < N; i++) {
    if (B.at(N-1) == A.at(i)) {
      cout << B.at(N-2) << endl;
    } else {
      cout << B.at(N-1) << endl;
    }
  }
}