#include<bits/stdc++.h>
#define ll long long
#define pr pair<ll,ll>
using namespace std;
bool vis[1000005];
int pri[1000005],cnt;
int n, num[2005];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	int ans = 0;
	for (int i = 0; i < n-2; i++) {
		for (int j = i + 1; j < n-1; j++) {
			int k = num[i] + num[j],p=num[j]-num[i];
			int s = lower_bound(num + j + 1, num + n,p+1) - num;
			int m = upper_bound(num + j + 1, num + n, k-1) - num;
			if (s <= m)ans += m - s;
		}
	}
	cout << ans;
	return 0;
}