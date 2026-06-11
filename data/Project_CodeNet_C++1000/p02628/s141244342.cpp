#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,k;
	scanf("%d%d", &n,&k);
	vector<int> a(n);
	for(int i=0; i<n; i++) scanf("%d", &a[i]);
	sort(a.begin(), a.end());
	int ans = 0;
	for(int i=0; i<k; i++) ans += a[i];
	cout << ans;
	return 0;
}