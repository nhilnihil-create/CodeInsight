#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int64_t> A(N);
  int64_t product = 1LL;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  for (int i = 0; i < N; i++) {
    if (A.at(i) == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  for (int i = 0; i < N; i++) {
    if (A.at(i) <= 1000000000000000000/product) {
      product *= A.at(i);
    } else {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << product << endl;
}