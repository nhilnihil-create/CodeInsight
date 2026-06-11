#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> X(N);
  int sum = 0;
  int summin = 1000000;
  for (int i = 0; i < N; i++) cin >> X.at(i);
  for (int i = 1; i <= 100; i++) {
    sum = 0;
    for (int j = 0; j < N; j++) {
      sum += pow(X.at(j) - i, 2);
    }
    if (summin > sum) {
      summin = sum;
    }
  }
  cout << summin << endl;
}