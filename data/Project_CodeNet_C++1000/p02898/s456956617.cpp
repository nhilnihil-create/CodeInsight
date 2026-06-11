#include <bits/stdc++.h>
#define ll long long int
#define endl "\n"
#define mod 1000000007
#define mem(a,val) memset(a,val,sizeof(a))
#define ps(x,noOfDecimal) fixed<<setprecision(noOfDecimal)<<x

using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	std::ios::sync_with_stdio(false);
	int t = 1;
	// cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector<int> arr(n);
		int ans = 0;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			if (arr[i] >= k)ans++;
		}
		cout << ans;
	}
	return 0;
}