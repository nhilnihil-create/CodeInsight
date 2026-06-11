#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

int n, a[200009];
string s;

int fun(int x, int y)
{
	long long tmp = 1;
	int cnt = 0;
	for (int i = x; i < x + y; i++) {
		cnt += a[i];
		if (a[i] == 0) {
			tmp *= cnt;
			tmp %= MOD;
			cnt--;
		}
	}
	return (int)tmp;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	if (s[0] == 'W') {
		cout << 0 << E;
		return 0;
	}
	a[0] = 1;
	for (int i = 1; i < n + n; i++) {
		if (s[i] == s[i - 1]) {
			a[i] = 1 ^ a[i - 1];
		}
		else {
			a[i] = a[i - 1];
		}
	}
	int cur = 0;
	bool flag = false;
	for (int i = 0; i < n + n; i++) {
		if (a[i]) cur++;
		else cur--;
		if (cur < 0) {
			flag = true;
			break;
		}
	}
	if (cur != 0 || flag) {
		cout << 0 << E;
	}
	else {
		long long ans = 0;
		int cnt = 0;
		ans = fun(0, n + n);
		for (int i = 1; i <= n; i++) {
			ans *= i;
			ans %= MOD;
		}
		cout << ans << E;
	}
	//system("pause");
	return 0;
}