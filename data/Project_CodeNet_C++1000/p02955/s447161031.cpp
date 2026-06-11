#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n, k;
	cin >> n >> k;
	int sum = 0;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	int ans = 0;
	for (int cur = 1; cur * cur <= sum; cur++) {
		if (sum % cur == 0) {
			// cur
			{
				vector<int> t = a;
				sort(t.begin(), t.end(), [&](int a, int b) {
					return a % cur < b % cur;
				});
				vector<int> suff(n);
				suff[n - 1] = cur - t[n - 1] % cur;
				for (int i = n - 2; i >= 0; i--)
					suff[i] = suff[i + 1] + cur - t[i] % cur;
				int min_k = 1e9 + 1;
				if (suff[0] == cur * n)
					min_k = 0;
				int neg = 0;
				for (int i = 0; i < n - 1; i++) {
					neg += t[i] % cur;
					if (suff[i + 1] == neg)
						min_k = min(min_k, neg);
				}
				if (min_k <= k)
					ans = max(ans, cur);
			}
			// sum / cur
			{
				int cur2 = sum / cur;
				vector<int> t = a;
				sort(t.begin(), t.end(), [&](int a, int b) {
					return a % cur2 < b % cur2;
				});
				vector<int> suff(n);
				suff[n - 1] = cur2 - t[n - 1] % cur2;
				for (int i = n - 2; i >= 0; i--)
					suff[i] = suff[i + 1] + cur2 - t[i] % cur2;
				int min_k = 1e9 + 1;
				if (suff[0] == cur2 * n)
					min_k = 0;
				int neg = 0;
				for (int i = 0; i < n - 1; i++) {
					neg += t[i] % cur2;
					if (suff[i + 1] == neg)
						min_k = min(min_k, neg);
				}
				if (min_k <= k)
					ans = max(ans, cur2);
			}
		}
	}

	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#if defined(_DEBUG)
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int q = 1;
	//cin >> q;
	for (; q > 0; q--) {
		solve();
		cout << endl;
	}
}