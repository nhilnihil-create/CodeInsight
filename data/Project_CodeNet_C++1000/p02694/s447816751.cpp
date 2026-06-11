#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll x;
  cin >> x;

  ll amount = 100;
  int i = 0;

  while (amount < x) {
    amount += amount / 100;
    i++;
  }

  cout << i << endl;

  return 0;
}
