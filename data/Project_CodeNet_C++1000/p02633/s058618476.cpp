#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int x;
  cin >> x;
  int l = lcm(x, 360);
  cout << l / x << '\n';
}