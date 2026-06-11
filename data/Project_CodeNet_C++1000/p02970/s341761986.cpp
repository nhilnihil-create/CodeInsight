#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N, D;
  cin >> N >> D;

  int range = 2 * D + 1;
  int ans = (N + range - 1) / range;
  cout << ans << endl;
}
