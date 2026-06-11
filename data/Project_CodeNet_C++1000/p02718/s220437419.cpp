#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  int sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    sum += A.at(i);
  }
  sort(A.begin(), A.end());
  int count = 0;
  for (int i = N-1; i >= 0; i--) {
    if (A.at(i) * 4 * M >= sum) {
      count++;
    } else {
      break;
    }
  }
  if (count >= M) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}