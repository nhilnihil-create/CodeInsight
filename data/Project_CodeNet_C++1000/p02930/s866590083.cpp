#include <bits/stdc++.h>
using namespace std;

int level(int d) {
  int s = 1;
  while (d % 2 == 0) {
    s++;
    d /= 2;
  }
  return s;
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      cout << level(j - i);
      if (j == n - 1) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
  }
}
