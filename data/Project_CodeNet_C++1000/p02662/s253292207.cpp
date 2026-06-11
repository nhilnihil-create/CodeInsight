#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mod = 998244353;
int n, s, a[3005], f[3005];

int main() {
	scanf("%d %d", &n, &s);
	f[0] = 1;
	rep(i, n) {
		scanf("%d", &a[i]);
		for (int j = s; ~j; -- j) {
			f[j] = 2LL * f[j] % mod;
			if (j >= a[i]) (f[j] += f[j - a[i]]) %= mod;
		}
	}
	printf("%d\n", f[s]);
	return 0;
}
