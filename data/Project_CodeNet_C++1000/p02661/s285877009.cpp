
// Problem : E - Count Median
// Contest : AtCoder - AtCoder Beginner Contest 169
// URL : https://atcoder.jp/contests/abc169/tasks/abc169_e
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
#define int long long
#define fastio                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);                       \
  cout.tie(0);
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define db1(x) cout << #x << "=" << x << endl
#define db2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z)                                                       \
  cout << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z \
       << endl
#define dbp(x) \
  cout << #x << "= {" << (x.first) << ", " << (x.second) << "}" << endl;
#define dbv(v)                         \
  {                                    \
    cout << #v << " : ";               \
    for (auto x : v) cout << x << ' '; \
    cout << endl;                      \
  }
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rep2(i, a, b) for (int i = a; i >= b; i--)
#define die(x) return cout << x << '\n', 0;

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

int32_t main() {
  fastio;

  int testcases;
  testcases = 1;
  // cin>>testcases;

  while (testcases--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, 0, n - 1) cin >> a[i] >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int x, y;
    if (n % 2 == 0) {
      rep(i, 0, n - 1) {
        a[i] = 2 * a[i];
        b[i] = 2 * b[i];
      }
      x = (a[n / 2] + a[n / 2 - 1]) / 2;
      y = (b[n / 2] + b[n / 2 - 1]) / 2;
    } else {
      x = a[n / 2];
      y = b[n / 2];
    }
    //  db2(x, y);
    cout << y - x + 1;
  }

  return 0;
}
