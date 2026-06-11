#include <algorithm>
#include <iostream>
#include <string>
#include <stack>
#include <utility>
#include <vector>
#include <math.h>

#define rep(i, n) for (auto i = 0; i < (n); i++)
#define MOD 1e9 + 7
typedef long long ll;

using namespace std;

int main() {
  int n, d;
  cin >> n >> d;
  int c = 0;
  rep(i, n) {
    ll x, y;
    cin >> x >> y;
    if (sqrt(x*x + y*y) <= d)
      c++;
  }
  cout << c << endl;

  return 0;
}

