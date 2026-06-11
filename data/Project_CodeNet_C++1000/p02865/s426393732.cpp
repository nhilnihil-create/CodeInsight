#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int count = 0;
  for (int i = 1; i <= n/2; ++i) {
    //    for (int j = 1; j < i; ++j) {
      if (n-i > n/2) {
        count++;
      }
    //}
  }
  cout << count;
}

