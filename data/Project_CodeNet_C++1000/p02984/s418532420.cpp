#include "bits/stdc++.h"
using namespace std;

// Inserted snippets: io, root
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }
// End snippets

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

  int n; read(n);
  vector<ll> v(n);
  rep(i, 0, n) read(v[i]);
  ll d = 0;
  rep(i, 0, n) d += (i % 2 == 0 ? v[i] : -v[i]);
  vector<ll> ans(n);
  ans[0] = d;
  rep(i, 1, n)
    ans[i] = 2 * v[i - 1] - ans[i - 1];
  rep(i, 0, n)
    cout << ans[i] << " ";
  cout << endl;
}
