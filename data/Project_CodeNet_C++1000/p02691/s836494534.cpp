#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0);

int n;

int main() {

	FAST;

	cin >> n;
	vector <int> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	map <int, int> cnt;
	intt ans = 0;
	for (int i = 1; i <= n; i ++) {
		ans += cnt[i - a[i]];
		cnt[i + a[i]] ++;
	}
	cout << ans << '\n';
	return 0;
}