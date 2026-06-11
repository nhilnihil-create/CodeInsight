#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  ll W, H, x, y;
  cin >> W >> H >> x >> y;
  cout << W * H / 2.0 << endl;
  if (x * 2 == W && y * 2 == H) cout << 1 << endl;
  else cout << 0 << endl;
  return 0;
}
