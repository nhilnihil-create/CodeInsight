// C - Cell Inversion
#include <bits/stdc++.h>

using namespace std;

#define	MOD	1000000007

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	string s;
	cin >> s;

	vector<int> a(2 * n);
	for (int i = 1; i < 2 * n; i++)
		if (s[i] == s[i - 1]) a[i] = a[i - 1] ^ 1;
		else a[i] = a[i - 1];

	if (s[0] == 'W' || s[n * 2 - 1] == 'W' || accumulate(a.begin(), a.end(), 0) != n) {
		cout << 0 << endl;
		return 0;
	}

	long long ans = 1;
	for (int i = 2 * n - 1, r = 0; i >= 0; i--)
		if (a[i]) r++;
		else ans = ans * r % MOD, r--;

	for (int i = 2; i <= n; i++) ans = ans * i % MOD;

	cout << ans << endl;

	return 0;
}
