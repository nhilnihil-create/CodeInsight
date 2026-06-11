#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin >> x;
  int a;
  a = x % 500;
  int t = 0;
  t += (x / 500) * 1000;
  t += (a / 5) * 5;
  cout << t << endl;
}
