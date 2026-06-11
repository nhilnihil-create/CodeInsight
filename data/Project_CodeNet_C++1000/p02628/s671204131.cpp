#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, k, ans, a[1005];
int main() {
	int i;
	cin >> n >> k;
	for(i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	for(i=0; i<k; i++) ans += a[i];
	cout << ans;
	return 0;
}
