#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;
int add(int a, int b) {
	return a + b >= mod ? a + b - mod : a + b;
}
int mul(int a, int b) {
	return int(1LL * a * b % mod);
}
const int N = 100005;

int n;
char s[N];
int pot[N];

int dp[N][2][2];
int f(int i, int less, int dif) {
	if(i == n) return 1;
	int &ans = dp[i][less][dif];
	if(~ans) return ans;
	ans = 0;
	if(less) {
		ans = add(ans, f(i + 1, 1, dif));
		ans = add(ans, f(i + 1, 1, 1));
		ans = add(ans, f(i + 1, 1, 1));
	}
	else {
		if(s[i] == '0') {
			ans = f(i + 1, 0, dif);
		}
		else {
			ans = f(i + 1, 1, dif);
			ans = add(ans, f(i + 1, 0, 0));
			if(dif) {
				ans = add(ans, f(i + 1, 1, 1));
			}
			else {
				ans = add(ans, f(i + 1, 0, 0));
			}
		}
	}
	return ans;
}

int main() {
	memset(dp, -1, sizeof dp);
	pot[0] = 1;
	scanf("%s", s);
	n = (int)strlen(s);

	printf("%d\n", f(0, 0, 0));

	int ans = 0;

	for(int i = 0; i < n; i++) {
		if(s[i] == '1') {

		}
	}
}
