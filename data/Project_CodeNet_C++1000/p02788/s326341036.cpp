#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cout << setprecision(10) << fixed;
	long long n, d, a;
	cin >> n >> d >> a;
	vector<pair<long long, long long>> m(n);
	vector<long long> used(n + 1, 0);
	for (int i = 0; i < n; ++i){
		cin >> m[i].first >> m[i].second;
	}
	sort(m.begin(), m.end());
	long long ans = 0;
	for (int i = 0, j = 0; i < n; ++i){
		while (j < n && m[i].first + 2 * d >= m[j].first){
			j++;
		}
		int need = max((1ll * m[i].second - used[i] * a + a - 1) / a, 0ll);
		ans += need;
		used[i] += need;
		used[j] -= need;
		used[i + 1] += used[i];
	}
	cout << ans;
	return 0;
}

