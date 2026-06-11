#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int count = 0;
  for (int a = 1; a < n; a++) {
    count += (n - 1) / a;
  }

  cout << count;
}
