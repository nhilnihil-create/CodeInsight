#include <bits/stdc++.h>
using namespace std;

const int N = 110000;
const long long INF = 1LL << 60;

int main() {
	
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	vector<int> a(n + 1);
	for (int i = 0; i <= n; i++) cin >> a[i];
	
	auto calc = [&]() {
		long long ans = 0;
		vector<long long> val(n + 2, 0);
		val[0] = 1;
		for (int i = 0; i <= n; i++) {
			if (val[i] > INF) val[i] = INF;
			if (val[i] < a[i]) return -1LL;
			val[i + 1] = (val[i] - a[i]) * 2;
		}
		long long tot = 0;
		for (int i = n; i >= 0; i--) {
			tot += a[i];
			ans += tot;
			tot = min(tot, val[i] / 2);
		}
		return ans;
	};
	
	cout << calc() << "\n";
	
	return 0;
}
