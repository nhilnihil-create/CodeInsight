#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  ll X;
  cin >> X;

  cout << (X / 500) * 1000 + ((X % 500) / 5) * 5 << endl;
  return 0;
}