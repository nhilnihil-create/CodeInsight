#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, greater<int>());
	long long resp = a[0];
	for (int i = 2; i < n; i++) {
		resp += 1ll * a[i / 2];
	}
	cout << resp << endl;
	return 0;
}