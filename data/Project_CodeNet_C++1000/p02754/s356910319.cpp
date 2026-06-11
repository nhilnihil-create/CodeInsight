#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, A, B, X=0;
  cin >> N >> A >> B;
  X = N/(A+B) * A;
  if (N%(A+B) >= A) {
    X += A;
  }
  else {
    X += N%(A+B);
  }
  cout << X << endl;
}