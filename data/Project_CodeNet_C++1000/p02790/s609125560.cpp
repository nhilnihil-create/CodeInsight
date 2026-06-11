#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int N = 0;
  for (int i = 0; i < max(a, b); i++) {
    N *= 10;
    N += min(a, b);
  }
  cout << N << endl;
}