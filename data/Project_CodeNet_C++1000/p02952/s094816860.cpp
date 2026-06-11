#include <bits/stdc++.h>
using namespace std;

int digit(int n) {
  if (0 <= n && n <= 9) {
    return 1;
  } else {
    return digit(n/10) + 1;
  }
}

int main() {
  int N;
  cin >> N;
  int count = 0;
  for (int i = 1; i <= N; i++) {
    if (digit(i) % 2 == 1) {
      count++;
    }
  }
  cout << count << endl;
}