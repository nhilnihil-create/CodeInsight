#include <bits/stdc++.h>

#define int long long
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

using namespace std;

const unsigned int M = 1e9 + 7;

int32_t main() {
	fastio;

	int h, n;
	cin >> h >> n;
	int a[n];
	for(int i = 0; i < n; ++i) cin >> a[i];
	sort(a, a + n);
	int sum = 0;
	for(int i = 0; i < n; ++i)
		sum += a[i];
	if(sum >= h) cout << "Yes";
	else cout << "No";

	return 0;
}
