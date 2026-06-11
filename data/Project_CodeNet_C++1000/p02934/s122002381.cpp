#include <bits/stdc++.h>
using namespace std;
#define int long long

double n, a, ans;
int32_t main() {
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a;
		ans += (1/a);
	}
	cout << 1/ans;
}