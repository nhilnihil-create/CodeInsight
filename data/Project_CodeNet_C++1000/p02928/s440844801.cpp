#include <bits/stdc++.h>
using namespace std;

// ----------- define --------------
#define int long long
#define vi vector<int>
#define ii pair<int,int>
#define fi first
#define sc second
#define stoi stoll
#define popcnt __builtin_popcount
#define getBit(x, k) ((x >> k) & 1)
#define all(x) (x).begin(),(x).end()
// ---------------------------------

const int mod = 1e9 + 7;

#define pow abcdef_pow
int pow(int a, int b) {
  if (b == 0) return 1;
  int t = pow(a, b / 2);
  t = (t * t) % mod;
  if (b % 2) return (t * a) % mod;
  return t;
}

int invc(vector<int> &a) {
  int ret = 0, n = a.size();
  for (int i = 0; i < n - 1; i++)
  for (int j = i + 1; j < n; j++) {
    if (a[i] > a[j]) {
      ret++;
      if (ret > mod) ret -= mod;
    }
  }
  return ret;
}

int rmod(int x) {
  return x % mod;
}

void Main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (auto &i : a) cin >> i;
  vector<int> b(all(a));
  b.insert(b.end(), all(a));
  int t1 = invc(a), t2 = invc(b) - t1 * 2;
  t1 = rmod(t1 * k);
  t2 = rmod(rmod(t2 * k) * rmod((k - 1) * pow(2, mod - 2)));
  cout << rmod(t1 + t2) << '\n';
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  cerr << "- ---- -- ----- <3\n";
#endif
  cin.tie(0)->sync_with_stdio(0);
  int T = 1;
  // cin >> T;
  while (T--) Main();
}
