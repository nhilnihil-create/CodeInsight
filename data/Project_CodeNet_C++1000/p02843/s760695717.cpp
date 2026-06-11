#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  int x;
  cin >> x;

  int r = x % 100;
  if (r % 5 == 0) r = r/5;
  else r = r/5 + 1;

  int k = x / 100;
  if (k >= r) cout << 1 << endl;
  else cout << 0 << endl;
   
  return 0;
}