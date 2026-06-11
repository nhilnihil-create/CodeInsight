#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define E "\n"

using namespace std;
const long long MOD = (long long)1e9 + 7;

int n;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	int tmp = n;
	bool ok = true;
	while (1) {
		if (tmp & 1) {
			if (tmp == 1)
				ok = false;
			break;
		}
		tmp = tmp >> 1;
	}
	if (n == 2) ok = false;
	if (ok) {
		cout << "Yes" << E;
		for (int i = 1; i < 3; i++) {
			cout << i << " " << i + 1 << E;
			cout << n + i << " " << n + i + 1 << E;
		}
		cout << 3 << " " << n + 1 << E;
		for (int i = 4; i + 1 <= n; i += 2) {
			cout << i << " " << i + 1 << E;
			cout << i + 1 << " " << 1 << E;
			cout << 1 << " " << n + i << E;
			cout << n + i << " " << n + i + 1 << E;
		}
		if (n % 2 == 0) {
			int tmp = 1;
			while (!(n & tmp)) {
				tmp = tmp << 1;
			}
			int a = n - tmp + 1;
			cout << a << " " << n << E;
			cout << tmp + n << " " << n + n << E;
		}
	}
	else {
		cout << "No" << E;
	}
	//system("pause");
	return 0;
}
