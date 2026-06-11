#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define per(i, a, b) for (int i = a; i >= b; i--)
#define ll long long
#define mset(s, _) memset(s, _, sizeof s)
#define ALL(a) (a).begin(), (a).end()
using namespace std;
int main(void) {
  int MAX = 2 * pow(10, 5) + 1;
  int N;
  cin >> N;
  vector<int> P;
  vector<int> min_P;
  int min_p = MAX;
  rep(i, 1, N) {
    int p;
    cin >> p;
    P.push_back(p);
    min_p = min(min_p, p);
    min_P.push_back(min_p);
  }

  int ans = 0;
  rep(i, 0, N - 1) {
    if (P[i] == min_P[i]) ans++;
    // cout << P[i] << ' ' << min_P[i] << endl;
  }
  cout << ans << endl;
  return 0;
}
