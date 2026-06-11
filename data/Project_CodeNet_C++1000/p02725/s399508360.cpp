#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int L, N;
  cin >> L >> N;
  vector<int> A(N);
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int i = 0; i < N; i++) {
    if (i == 0) {
      B.at(i) = A.at(0) + L - A.at(N-1);
    } else {
      B.at(i) = A.at(i) - A.at(i - 1);
    }
  }
  sort(B.begin(), B.end());
  cout << L - B.at(N-1) << endl;
}