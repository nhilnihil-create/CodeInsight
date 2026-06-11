#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int K;
  cin >> K;
  vector<int> A(K, 0);
  A.at(0) = 7 % K;
  for(int i = 0; i < K - 1; i++) {
    A.at(i + 1) = (A.at(i) * 10 + 7) % K;
  }
  bool N = true;
  for(int i = 0; i < K; i++) {
    if (A.at(i) == 0) {
      cout << i + 1 <<endl;
      N = false;
      break;
    }
  }
  if (N) cout << "-1" << endl;
}