#include <bits/stdc++.h>
using namespace std;

int main() {
  long X;
  cin >> X;
  long now = 100, cnt = 0;
  while (now < X) now += now / 100, cnt++;
  cout << cnt << "\n";
}