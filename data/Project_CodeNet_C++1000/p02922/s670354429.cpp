#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, n = 0;
  cin >> a >> b;
  while(a * n - n + 1 < b) n++;
  cout << n << endl;
}