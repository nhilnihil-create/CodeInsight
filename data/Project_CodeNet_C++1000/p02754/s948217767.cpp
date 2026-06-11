#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int64_t n, a, b;
  cin >> n >> a >> b;
  if (n % (a + b) > a) cout << (n / (a + b)) * a + a << endl;
  else cout << (n / (a + b)) * a + n % (a + b) << endl;
}