// #pragma GCC target("avx,avx2,fma")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int n;
	cin >> n;
	vector<ll> cnt(n);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		cnt[a - 1]++;
	}

	sort(cnt.rbegin(), cnt.rend());
	int cur = 0;
	cnt.insert(cnt.begin(), n);
	vector<ll> pref(n + 1);
	for (int i = 0; i <= n; i++) {
		pref[i] = (i ? pref[i - 1] : 0) + cnt[i];
	}

	for (int i = 1; i <= n; i++) {
		cur += cnt[i];
		int rem = n - cur;
		int l = 0, r = i;
		while (r - l > 1) {
			int mid = (l + r) / 2;
			ll need = cnt[i - mid] * (mid + 1) - pref[i] + pref[i - mid - 1];
			if (rem < need) {
				r = mid;
			} else {
				l = mid;
			}
		}
		ll need = cnt[i - l] * (l + 1) - pref[i] + pref[i - l - 1];
		cout << cnt[i - l] + (rem - need) / (l + 1) << " \n"[i == n];
	}
    return 0;
}