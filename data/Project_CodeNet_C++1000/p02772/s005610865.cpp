#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() { 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, a[666];
	cin >> n;
	bool ok = true;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0 && a[i] % 3 != 0 && a[i] % 5 != 0) ok = false;
	}
	if (ok) cout << "APPROVED"; else cout << "DENIED";
	return 0;
}