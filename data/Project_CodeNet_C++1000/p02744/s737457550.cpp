#include <bits/stdc++.h>
#define IOS                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
ll bpow(ll b, ll p, ll m = 1000000007LL) {
  ll rt = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      rt = rt * b % m;
  return rt;
}
string s = "a";
int n;
set<string> v;
void solve(int u) {
  if (u == n - 1) {
    v.insert(s);
    return;
  }
  char mx = 0;
  for (int i = 0; i <= u; i++) {
    s += s[i];
    mx = max(mx, s[i]);
    solve(u + 1);
    s.pop_back();
  }
  s += mx + 1;
  solve(u + 1);
  s.pop_back();
}
int main() {
  IOS;
  cin >> n;
  solve(0);
  for (string i : v) {
    cout << i << endl;
  }
}
