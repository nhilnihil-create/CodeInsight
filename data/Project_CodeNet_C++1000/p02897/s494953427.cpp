#include <bits/stdc++.h>

using namespace std;

int main() {
#ifdef _DEBUG
	freopen("_in" , "r", stdin );
	freopen("_out", "w", stdout);
#endif
	int n; cin >> n;
	cout << fixed << setprecision(10);
	if (n % 2 == 0) cout << "0.5000000000\n";
	else cout << (n / 2 + 1) / double(n) << '\n';
}
