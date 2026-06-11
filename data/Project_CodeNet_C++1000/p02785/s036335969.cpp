#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define ll long long
#define mset(s, _) memset(s, _, sizeof s)
#define ALL(a) (a).begin(), (a).end()
using namespace std;

int main(void) {
  int N, K;
  cin >> N >> K;
  vector<int> H;
  rep(i, 1, N) {
    int h;
    cin >> h;
    H.push_back(h);
  }

  sort(ALL(H));
  reverse(ALL(H));

  ll ans = 0;
  rep(i, K, N - 1) { ans += H[i]; }
  cout << ans << endl;
  return 0;
}
