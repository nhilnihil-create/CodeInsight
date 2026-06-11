#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll X, y = 100;
  cin >> X;
  //100*(1.01)^y>X
  int i;
  for (i = 0; y < X; ++i) {
    y += y / 100;
  }
  cout << i << "\n";

  return 0;
}
