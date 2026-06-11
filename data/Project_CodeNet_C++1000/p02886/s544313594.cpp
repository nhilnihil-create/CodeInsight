#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("_in" , "r", stdin );
	freopen("_out", "w", stdout);
#endif
	int n; cin >> n;
	int s = 0;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n - 1; i++)
	for (int j = i + 1; j < n; j++) {
		s += a[i] * a[j];
	}
	cout << s << '\n';
}
