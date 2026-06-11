
// Problem : A - Multiplication 1
// Contest : AtCoder - AtCoder Beginner Contest 169
// URL : https://atcoder.jp/contests/abc169/tasks/abc169_a
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
    int a, b;
    cin >> a >> b;
    cout << a * b;
  }

  return 0;
}
