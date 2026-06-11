#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ar array
#define sz(a) (int) a.size()
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define vi vector<int>
#define pb push_back
#define eb emplace_back
#define ii pair<int, int>
#define bit(x, y) ((x >> y) & 1)
#define lwb lower_bound
#define upb upper_bound

#define F_OR(i, a, b, s) for (int i = (a); ((s) > 0 ? i < (b) : i > (b)); i += (s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)

int main(void) {
  ios::sync_with_stdio(0); cin.tie(0);

  int n;
  cin >> n;
  cout << (n - 1) / 2 << '\n';
}
