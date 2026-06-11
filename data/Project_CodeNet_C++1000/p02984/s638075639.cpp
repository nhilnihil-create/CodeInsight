#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N), R(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) R.at(0) += A.at(i);
    else R.at(0) -= A.at(i);
  }
  for (int i = 1; i < N; i++) R.at(i) = 2 * A.at(i - 1) - R.at(i - 1);
  for (int i = 0; i < N; i++) cout << R.at(i) << " ";
  cout << endl;
}