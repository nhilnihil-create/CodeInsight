#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef pair<int, int> p;
typedef long long ll;
const int inf = 1000000007;
int main() {
  int k, a, b;
  cin >> k >> a >> b;
  bool ok = false;
  for (int i = 0; i < 5000; i++) {
    if (ok) break;
    if (a <= k * i && k * i <= b) ok = true;
  }
  if (ok)
    cout << "OK" << endl;
  else
    cout << "NG" << endl;
  return 0;
}