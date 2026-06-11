#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x; cin >> x;
  int i = 0;
  for (long long a = 100; x > a; a += a / 100, i++);
  cout << i << endl;
}