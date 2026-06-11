#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1000000000000;
const int mod = 1000000007;
vector<int> res;
void divisor(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			res.push_back(i);
			if (i != n / i) res.push_back(n / i);
		}
	}
	if (n != 1) { res.push_back(n); }
}
int test[12345678];
signed main() {
	int n, k, cnt = 0, ans = 1; cin >> n >> k;
	vector<int>kari;
	for (int h = 0; h < n; h++) {
		cin >> test[h]; cnt += test[h];
	}
	divisor(cnt);
	for (int h = 0; h < res.size(); h++) {
		for (int i = 0; i < n; i++) {
			if (test[i] % res[h] != 0) {
				kari.push_back(test[i] % res[h]);
			}
		}
		sort(kari.begin(), kari.end()); 
		int a = 0, b = 0, ok = 0;
		for (int i = 0; i < kari.size(); i++) {
			a += res[h] - kari[i];
		}
		for (int i = 0; i < kari.size(); i++) {
			a -= res[h] - kari[i]; b += kari[i];
			if (a == b) { ok = a; }
		}
		if (ok <= k) { ans = max(ans, res[h]); }
		kari.clear();
	}
	cout << ans << endl;
	return 0;
}