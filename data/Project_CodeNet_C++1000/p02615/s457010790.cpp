#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, a[200000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	sort(a, a+n, greater<int>());
	ll ans=0;
	for (int i=1; i<n; ++i)
		ans+=a[i/2];
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/
