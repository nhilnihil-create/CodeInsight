#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  for (int i = -(N-1); i < N; i++) {
    cout << X + i;
    if (i < N-1) {
      cout << ' ';
    } else {
      cout << endl;
    }
  }
}