#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  long long money = 1000, stock = 0;
  bool prev = false;
  for (int i = 0; i < N - 1; i++) {
    if (prev) {
      money += stock * A[i];
      stock = 0;
      prev = false;
    }
    if (A[i] < A[i + 1]) {
      long long num = money / A[i];
      money -= num * A[i];
      stock = num;
      prev = true;
    }
  }
  if (prev) {
    money += stock * A[N - 1];
    prev = false;
  }
  cout << money << endl;
  return 0;
}