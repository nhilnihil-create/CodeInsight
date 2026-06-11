#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
//#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout << (x) << " "
#define ce(x) cerr << (x) << "\n"
#define cesp(x) cerr << (x) << " "
#define pb push_back
#define mp make_pair
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
#define Would
#define you
#define please

//解説みてます

ll dp[2002];
int main() {
	//cin.tie(0);
	//ios::sync_with_stdio(false);


	int N = 0;
	char c;
	while ((c = getchar_unlocked()) >= '0') N = N * 10 + c - '0';
	ll A[2000];
	rep(i, N) {
		int a = 0;
		while ((c = getchar_unlocked()) >= '0') a = a * 10 + c - '0';
		A[i] = ll(a) << 30 | i;
	}
	sort(A, A + N);
	const ll m = (1ll << 30) - 1;
	for (int i = N - 1; i >= 0; i--) {
		int a = A[i] & m;
		ll aa = A[i] >> 30;

		for (int j = N - i - 1; j >= 0; j--) {
			if (dp[j + 1] < dp[j] + abs(a - j) * aa) dp[j + 1] = dp[j] + abs(a - j) * aa;
			dp[j] += abs(a - j - i) * aa;
		}
	}
	ll kotae = 0;
	rep(i, N + 1) if (kotae < dp[i]) kotae = dp[i];

	printf("%lld", kotae);

	Would you please return 0;
}