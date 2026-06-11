#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long mypow(long long a, long long b) {
  if (b == 0) {
	  return 1LL;
	}
  if (b % 2 == 1) {
	  return (a * mypow(a, b - 1)) % mod;
	}
  long long c = mypow(a, b / 2);
  return (c * c) % mod;
}

int main() {
  int n;
  cin >> n;
  vector <int> d(n);
  int M = 0;
  for (int i = 0; i < n; i++) {
	  cin >> d[i];
	  M = max(d[i], M);
	}
  if (d[0] != 0) {
	  cout << 0 << endl;
	  return 0;
	}
  vector <int> cnt(M + 1, 0);
  for (int i = 0; i < n; i++) {
	  cnt[d[i]]++;
	}
  if (cnt[0] > 1) {
	  cout << 0 << endl;
	  return 0;
	}
  long long ans = 1;
  for (int i = 1; i <= M; i++) {
	  ans = (ans * mypow(cnt[i - 1], cnt[i])) % mod;
	}
  cout << ans << endl;
  return 0;
}
