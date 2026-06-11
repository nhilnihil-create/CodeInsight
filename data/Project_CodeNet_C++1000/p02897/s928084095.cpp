#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  if (N%2 == 1) {
    cout << 1.0 * (1 + N/2) / N << endl;
  }
  else {
    cout << 1.0 / 2.0 << endl;
  }
}