#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

typedef pair<int, int> pii;

const int MAXN = 1e5;

int a[MAXN];
int sum[MAXN][4];

int main() {
	int n; cin >> n;
	string s; cin >> s;

	for (int i = 0; i < n; i++) {
		if (s[i] == 'R') a[i+1] = 1;
		if (s[i] == 'G') a[i+1] = 2;
		if (s[i] == 'B') a[i+1] = 3;
	}

	for (int i = n; i >= 1; i--) for (int j = 1; j <= 3; j++) {
		sum[i][j] = (a[i] == j) + sum[i+1][j];
	}

	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (a[i] == a[j]) continue;
			int z = 1^2^3^a[i]^a[j];

			ans += sum[j+1][z];
			if (a[j + j - i] == z) ans--;
		}
	}

	cout << ans << '\n';
}