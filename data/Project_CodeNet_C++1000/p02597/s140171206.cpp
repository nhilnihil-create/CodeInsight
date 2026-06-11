#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N;
  string c;
  cin >> N >> c;
  int a = 0, b = 0;
  rep(i,N) if (c[i] == 'R') a++;
  int ans = max(a, b);
  rep(i,N){
    if (c[i] == 'R') a--;
    else b++;
    int now = max(a, b);
    ans = min(ans, now);
  }
  cout << ans << endl;
  return 0;
}
