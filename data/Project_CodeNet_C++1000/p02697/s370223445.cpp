#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int N, M;
  cin >> N >> M;

  int l = 1;
  int r = N;
  if (N % 2 == 1) {
    REP(i, M) {
      cout << l << " " << r << endl;
      ++l;
      --r;
    }
  } else {
    set<pair<int, int>> found;

    REP(i, M) {
      cout << l << " " << r << endl;
      // cout << l << " " << r << ":" << abs(r - l) << ":" << abs(l + N - r)
      //  << endl;
      ++l;
      --r;
      if (abs(r - l) == abs(l + N - r) ||
          found.find(make_pair(min(abs(r - l), abs(l + N - r)),
                               max(abs(r - l), abs(l + N - r)))) !=
              found.end()) {
        ++l;
      }
      found.insert(make_pair(min(abs(r - l), abs(l + N - r)),
                             max(abs(r - l), abs(l + N - r))));
    }
  }

  return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// using ll = long long;
// template <class T, class U> inline bool chmin(T &x, U y) {
//   if (x > y) {
//     x = y;
//     return true;
//   }
//   return false;
// }
// template <class T, class U> inline bool chmax(T &x, U y) {
//   if (x < y) {
//     x = y;
//     return true;
//   }
//   return false;
// }
// #define fr(i, n) for (int i = 0; i < (n); ++i)
// #define Fr(i, n) for (int i = 1; i <= (n); ++i)
// #define ifr(i, n) for (int i = (n)-1; i >= 0; --i)
// #define iFr(i, n) for (int i = (n); i > 0; --i)

// int main() {
//   cin.tie(nullptr);
//   ios::sync_with_stdio(false);
//   int n, m;
//   cin >> n >> m;
//   bool f{true};
//   if (n & 1) {
//     int l = 1, r = n;
//     fr(i, m) {
//       cout << l << " " << r << '\n';
//       ++l, --r;
//     }
//   } else {
//     int l = 1, r = n;
//     fr(i, m) {
//       cout << l << " " << r << '\n';
//       ++l, --r;
//       if (f && 4 * l > n)
//         ++l, f = false;
//     }
//   }
// }
