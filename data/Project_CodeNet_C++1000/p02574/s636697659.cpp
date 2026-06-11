#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6 + 100;
int n, x, ans, maxx, res, i, j, num[N];
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
	cin >> n >> ans;
	num[ans]++;
	for (i = 2; i <= n; i++) {
		cin >> x;
		num[x]++;
		maxx = max(maxx, x);
		ans = gcd(ans, x);
	}
	if (ans != 1) cout << "not coprime\n";
	else {
		for (i = 2; i <= maxx; i++) {
			for (j = i, res = 0; j <= maxx; j += i) res += num[j];
			if (res > 1) {
				cout << "setwise coprime";
				return 0;
			}
		}
		cout << "pairwise coprime\n";
	}
	return 0; 
}
