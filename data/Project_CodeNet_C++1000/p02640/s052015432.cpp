#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int x, y;
  cin >> x >> y;

  string ans = "No";
  for (int i = 0; i <= x; i++) {
    if (2 * i + 4 * (x - i) == y) ans = "Yes";
  }

  cout << ans << endl;
}
