#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  int result = 0;
  if (K < A) {
    result += K;
    K = 0;
  }
  else {
    result += A;
    K -= A;
  }
  if (K < B) {
    K -= 0;
  }
  else {
    K -= B;
  }
  result -= K;
  cout << result << endl;
  return 0;
}
