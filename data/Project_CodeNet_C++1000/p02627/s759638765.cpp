#include <bits/stdc++.h>

#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)

using namespace std;

using ll = long long;
using P = pair<int, int>;

int main() {
  char c;
  cin >> c;
  if (c >= 'A' && c <= 'Z') {
    cout << 'A' << endl;
  } else {
    cout << 'a' << endl;
  }
  return 0;
}
