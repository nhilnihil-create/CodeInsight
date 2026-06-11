#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 69;

long long n, m, v, p;
long long ar[N], pre[N];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	cin >> n >> m >> v >> p;
	for(int i = 1; i <= n; i++) {
		cin >> ar[i];
	}
	sort(ar + 1, ar + n + 1, greater<long long>());
	for(int i = 1; i <= n; i++) {
		pre[i] = pre[i - 1] + ar[i];
	}
	int ans = p;
	for(int i = p + 1; i <= n; i++) {
		if(ar[i] + m < ar[p])
			continue;
		long long sumVote = v * m;
		sumVote -= m;
		sumVote -= (p - 1) * m;
		sumVote -= (n - i) * m;
		if(sumVote <= 0) {
			ans++;
			continue;
		}
		sumVote -= ((i - p) * (ar[i] + m) - pre[i - 1] + pre[p - 1]);
		if(sumVote <= 0) {
			ans++;
			continue;
		}
	}

	cout << ans << "\n";
	return 0;
}