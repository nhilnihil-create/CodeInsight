#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
ll m = 1e9 + 7;

int main() {
  int a,b,c;
  cin >> a >> b >> c;
  int k;
  cin >> k;

  for (int i = 0; i <= k; i++) {
    for ( int j = 0; j <= (k-i); j++)
    if (a < pow(2,i) * b && pow(2,i) * b < pow(2,j) * c) {
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;

}