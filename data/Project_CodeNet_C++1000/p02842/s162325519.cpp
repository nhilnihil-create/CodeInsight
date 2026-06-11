#include <math.h>

#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
  double n;
  cin >> n;

  double price = floor(n / 1.1);
  for (double price; price <= n; price++) {
    if (floor(price * 1.08) == n) {
      cout << price;
      break;
    }
    if (price == n) cout << ":(";
  }
  return 0;
}
