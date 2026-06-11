#include <bits/stdc++.h>
using namespace std;

// #define int ll
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using si = set<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define fastio    ios::sync_with_stdio(0); cin.tie(0)
#define rep(i, n) for (int i = 0; i < n; i++)
#define dotc()    int tcs; if (cin >> tcs) rep(tc, tcs)
#define sz(x)     (int)x.size()
#define eb        emplace_back
#define pb        push_back
#define mp        make_pair
#define all(x)    x.begin(), x.end()
#define rall(x)   x.rbegin(), x.rend()
#define fi        first
#define se        second

int inf(0x3fffffff);
int mod(1000000007);
double pi(acos(-1.0));

int32_t main() {
  fastio;
#ifdef LOCAL
  freopen("io\\in.txt", "r", stdin);
  freopen("io\\out.txt", "w", stdout);
#endif

  int n, k, r, s, p;
  string t;
  cin >> n >> k >> r >> s >> p >> t;

  int sum = 0;
  string t2;
  rep(i, n) {
    if (t[i] == 's') {
      if (i >= k && t2[i - k] == 'r') t2.pb('x');
      else sum += r, t2.pb('r');
    }
    else if (t[i] == 'r') {
      if (i >= k && t2[i - k] == 'p') t2.pb('x');
      else sum += p, t2.pb('p');
    }
    else if (t[i] == 'p') {
      if (i >= k && t2[i - k] == 's') t2.pb('x');
      else sum += s, t2.pb('s');
    }
  }
  cout << sum;

  return 0;
}
