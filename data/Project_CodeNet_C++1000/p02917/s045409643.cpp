#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int sum = 0;
  vector<int> B(N - 1);
  vector<int> A(N);
  for (int i = 0; i < N - 1; i++) cin >> B.at(i);
  for (int i = 0; i < N; i++) {
    if (i == 0) {
      A.at(0) = B.at(0);
    }
    else if (i == N-1) {
      A.at(i) = B.at(i-1);
    }
    else {
      A.at(i) = min(B.at(i-1), B.at(i));
    }
  }
  for (int i = 0; i < N; i++) sum += A.at(i);
  cout << sum << endl;
}