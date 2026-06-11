#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
using pii = pair<int, int>;
int main() {
  int x;
  cin >> x;

  int a = 400;

  for (int i = 0; i < 8; i++) {
    if (a <= x && x < a + 200) {
      cout << 8 - i << endl;
      return 0;
    } else {
      a += 200;
    }
  }
}