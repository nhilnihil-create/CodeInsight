#include <bits/stdc++.h>
#define rep(i, a, n) for (int i = a; i < n; i++)
#define repr(i, a, n) for (int i = n - 1; i >= a; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];

  vector<int> x(n + 1, 0);
  vector<int> ans;
  repr(i, 1, n + 1) {
    int c = 0;
    for (int j = 2 * i; j < n + 1; j += i)
      c += x[j];

    if (a[i - 1] % 2 == 0 && c % 2 == 1) {
      x[i] = 1;
      ans.push_back(i);
    }
    if (a[i - 1] % 2 == 1 && c % 2 == 0) {
      x[i] = 1;
      ans.push_back(i);
    }
  }

  int m = ans.size();
  cout << m << endl;
  repr(i, 0, m) {
    if (i < m-1)
      cout << " ";
    cout << ans[i];
  }
  cout << endl;
}
