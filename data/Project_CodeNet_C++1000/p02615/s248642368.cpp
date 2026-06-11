#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long ans = 0;
long long a[200002];
bool b = false;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	ans += a[n];
	int tot = (n - 2) / 2;
	if ((n - 2) % 2 == 1) {
		b = true;
	}
	else {
		b = false;
	}
	for (int i = n - 1; i >= n - tot; i--) {
		ans = ans + a[i] * 2;
		//cout << a[i] << endl;
	}
	//cout << ans << endl;
	if (b) ans += a[2 + tot];
	cout << ans << endl;
	return 0;
}
