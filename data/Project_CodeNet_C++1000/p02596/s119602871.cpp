#include <bits/stdc++.h>
using namespace std;

int main() {
  int K, sum = 0;
  cin >> K;
  if (K % 2 == 0 || K % 5 == 0) {
    sum = -1;
  }
  else {
    K *= 9;
    if (K % 7 == 0) {
      K /= 7;
    }
    int s = 0, i = 10;
    while (s == 0) {
      sum++;
      i %= K;
      if (i == 1) {
        s = 1;
      }
      i *= 10;
    }
  }
  cout << sum << endl;
}