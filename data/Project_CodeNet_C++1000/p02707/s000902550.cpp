#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> A(N-1);
  vector<int> B(N);
  for (int i = 0; i < N-1; i++) {
    cin >> A.at(i);
    B.at(A.at(i) - 1)++;
  }
  for (int i = 0; i < N; i++) {
    cout << B.at(i) << endl;
  }
}