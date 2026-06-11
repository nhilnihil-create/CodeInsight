#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int n, x, t;
  cin >> n >> x >> t;
  int k = n / x;
  if (n % x != 0) k++;
  cout << k * t << endl;
  return 0;
}