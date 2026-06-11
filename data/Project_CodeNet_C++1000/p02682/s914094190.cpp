#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, C, N;
  cin >> A >> B >> C >> N;
  if (N <= A) {
    cout << N << endl;
  } else if (N <= A+B) {
    cout << A << endl;
  } else {
    cout << A - (N - A - B) << endl;
  }
}