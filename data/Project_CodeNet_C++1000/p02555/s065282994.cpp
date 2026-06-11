#include <bits/stdc++.h>

using namespace std;

const int N = 2100, MOD = 1e9 + 7;
int n;
long long f[N];

int main () {
	cin >> n;
	for (int i = 3; i <= n; i ++ ) f[i] = 1;
	for (int i = 6; i <= n; i ++ ) {
		for (int j = i - 3; j >= 3; j -- ) {
			f[i] += f[j];
			f[i] %= MOD;
		}
	}
	cout << f[n] << endl;
	return 0;
}
