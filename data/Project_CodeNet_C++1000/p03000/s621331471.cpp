/*
  no pain, no gain
*/

#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2,fma")
#include <bits/stdc++.h>
#define fr first
#define sc second
#define pb push_back
#define szof(s) (int)s.size()
#define all(s) s.begin(), s.end()
#define pii pair<int, int>
#define all(s) s.begin(), s.end()
#define prev myrza4321
#define y1 myrza1234
#define OK puts("OK")
using namespace std;

const int N = (int)1e5 + 5;
const int INF = 0x3f3f3f3f;

main() {
  int n, x;
  cin >> n >> x;
  int pnt = 0, ans = 1;
  while (n--) {
    int add;
    scanf("%d", &add);
    pnt += add;
    if (pnt <= x) {
      ans++;
    }
  }
  cout << ans;
}
