#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<double> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  double sum = 0;
  for (int i = 0; i < N; i++) sum += 1/A.at(i);
  cout << 1/sum << endl;
}