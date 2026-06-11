#include <bits/stdc++.h>
using namespace std;
#define REP(i, n)  for (int i = 0; i < (int) (n); i++)
#define REP1(i, n) for (int i = 1; i <= (int) (n); i++)
#define all(x)     (x).begin(), (x).end()
#define SZ(x)      ((int) (x).size())
using ll = long long;

int main() {
  int n, k, s;
  cin >> n >> k >> s;
  vector <int> ans(n, s == 1e9 ? s - 1 : s + 1);
  REP(i, k) {
	ans[i] = s;
  }
  REP(i, n - 1) {
	cout << ans[i] << " ";
  }
  cout << ans[n - 1] << endl;
  return 0;
}
