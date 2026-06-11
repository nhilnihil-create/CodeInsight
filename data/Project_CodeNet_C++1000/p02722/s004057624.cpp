#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
#ifdef _DEBUG
	//freopen("in", "r", stdin);
#endif
	int n; cin >> n;
  if (n == 2) {
    cout << 1 << '\n';
    return 0;
  }
	int cnt = 2;
	for (int i = 2; i * i <= n - 1; i++) {
		if ((n - 1) % i == 0) {
			cnt++;
			if ((n - 1) / i != i) cnt++;
		}
	}
  for (int i = 2; i * i <= n; i++) {
    if (n % i) continue;
    vector<int> v = {i};
    if (n / i != i) v.push_back(n / i);
    for (auto j : v) {
      int t = n;
      while (t % j == 0) t /= j;
      if (t % j == 1) cnt++;
    }
  }
	cout << cnt << '\n';
}
