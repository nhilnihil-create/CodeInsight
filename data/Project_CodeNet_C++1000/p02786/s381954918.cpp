#include <bits/stdc++.h>
using namespace std;

int main() {
  long H;
  cin >> H;
  int cnt = 0;
  while (H) H /= 2, cnt++;
  cout << (long) pow(2, cnt) - 1 << "\n";
}