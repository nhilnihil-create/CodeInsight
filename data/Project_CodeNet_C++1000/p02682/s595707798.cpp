#include <bits/stdc++.h>
using namespace std;

int main() {
  long long A, B, C, K, M;
  cin >> A >> B >> C >> K;
  if (K <= A) {
    M = K;
  }
  else if (K <= A+B) {
    M = A;
  }
  else {
    M = A -(K-(A+B));
  }
  cout << M << endl;
}