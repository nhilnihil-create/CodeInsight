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
  int n;
  cin >> n;
  if (n % 1000 == 0)
    cout << 0 << endl;
  else
    cout << (1000 - (n % 1000)) << endl;

  return 0;
}

