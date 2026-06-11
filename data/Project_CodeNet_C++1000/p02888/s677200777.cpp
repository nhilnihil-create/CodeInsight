#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define rep1(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); i++)
#define get4(_1, _2, _3, _4, ...) _4
#define rep(...) get4(__VA_ARGS__, rep2, rep1)(__VA_ARGS__)
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> l(n);
  rep(i, n) cin >> l[i];
  sort(all(l));
  ll ans = 0;
  rep(i, n) {
    rep(j, i + 1, n) {
      int a = l[i];
      int b = l[j];
      int upper = n;
      int lower = j;
      while (upper - lower > 1) {
        int mid = (upper + lower) / 2;
        int c = l[mid];
        if (j == mid) continue;
        if (c < a + b) {
          lower = mid;
        } else {
          upper = mid;
        }
      }
      ans += lower - (j + 1) + 1;
    }
  }
  cout << ans << '\n';
  return 0;
}
