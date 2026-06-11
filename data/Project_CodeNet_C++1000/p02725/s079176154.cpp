#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int N = 2e5 + 100;
int n, a[N], k;

int main() {
	
	cin >> k >> n;
	
	int ans = 0x3f3f3f3f;
	
	for(int i = 0; i < n; i++) cin >> a[i];
	
	for(int i = 0; i < n; i++) {
		int pre = (i-1+n) % n;
		int nex = (i+1) % n;
		
		int x = (a[pre] - a[i] + k) % k;
		ans = min(ans, x);
		x = (a[i] - a[nex] + k) % k;
		ans = min(ans, x);
	}
	
	cout << ans << endl;
	return 0;	
} 