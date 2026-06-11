#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
	int n; cin >> n;
	int a[n];
	for(int i = 0; i < n; i++) cin >> a[i];

	long long res = 1;
	int r = 0, b = 0, g = 0;
	for (int i = 0; i < n; i++)
	{
		int c = (r == a[i]) + (b == a[i]) + (g == a[i]);
		res = res * c % MOD;
		if(r == a[i]) r++;
		else if(b == a[i]) b++;
		else g++;
	}
	cout << res << endl;
	return 0;
}

