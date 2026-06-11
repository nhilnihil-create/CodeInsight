#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1001001001;

int main() {
  int n;
  string c;
  cin >> n >> c;
  int red = 0;
  for (char r : c) {
    if (r == 'R') red++;
  }
  int ans = 0;
  for (int i = 0; i < red; i++) {
    if (c[i] == 'W') ans++;
  }

  cout << ans << endl;
  return 0;
}