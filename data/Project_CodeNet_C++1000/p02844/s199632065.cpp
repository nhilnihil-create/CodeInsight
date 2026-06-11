#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
const int MOD = (int)1e9 + 7;
const double PI = 3.14159265358979323846;
template <class T, class U>
void chmin(T& t, const U& u) {
  if (t > u) t = u;
}
template <class T, class U>
void chmax(T& t, const U& u) {
  if (t < u) t = u;
}

int main(void) {
  int n;
  string s;
  cin >> n >> s;
  bool find[1009] = {false};
  rep(i, 1000) {
    int pos = 0;
    int d[] = {i / 100, (i % 100) / 10, i % 10};
    int dpos = 0;
    while (pos < n) {
      if (d[dpos] + '0' == s[pos]) dpos++;
      pos++;
    }
    if (dpos > 2) find[i] = true;
  }
  int res = 0;
  rep(i, 1000) if (find[i]) res++;
  cout << res << endl;
  return 0;
}