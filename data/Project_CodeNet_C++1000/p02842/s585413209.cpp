#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  ll n;
  cin >> n;

  rep(x,50000) {
    if ((int)(x * 1.08) == n) {
      cout << x << endl;
      return 0;
    }
  }

  cout << ":(" << endl;
  return 0;
}