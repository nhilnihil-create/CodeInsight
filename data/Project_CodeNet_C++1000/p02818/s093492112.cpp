#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
  int64_t a, b, k;
  cin >> a >> b >> k;
  if(a >= k) cout << a-k << ' ' << b << endl;
  else if (a < k && a+b >= k) cout << 0 << ' ' << a+b-k << endl;
  else cout << 0 << ' ' << 0 << endl;
}