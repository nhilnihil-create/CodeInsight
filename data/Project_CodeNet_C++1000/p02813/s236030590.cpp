#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ii pair<int,int>
#define fi first
#define sc second

#define all(x) (x).begin(),(x).end()

int cal(vector<int> &a, int n) {
  vector<int> b(n);
  for (int i = 0; i < n; i++) b[i] = i + 1;
  int cnt = 1;
  while (a != b) {
    cnt++;
    next_permutation(all(b));
  }
  return cnt;
}

signed main() {
#ifdef _DEBUG
  // freopen("in" , "r", stdin );
  // freopen("out", "w", stdout);
#endif
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (auto &i : a) cin >> i;
  for (auto &i : b) cin >> i;
  cout << abs(cal(a, n) - cal(b, n)) << '\n';
}
