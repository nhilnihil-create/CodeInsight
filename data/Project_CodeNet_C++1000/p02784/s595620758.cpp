#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, N;
  cin >> H >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  sort(A.begin(), A.end());
  int sum = 0;
  for (int i = N-1; i >= 0; i--) {
    sum += A.at(i);
    if (H <= sum) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}