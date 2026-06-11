#include <iostream>
#include <algorithm>
#include <string>
#define flush fflush(stdout)
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;
const int mod = (int)1e9 + 7, INF = (int)1e9;
const int di[4] = { 1,0,-1,0 }, dj[4] = { 0,1,0,-1 };


int main(void) {
	int n, p, i;
	ll r, dd, k[200003] = {}, mr[10003] = {}, ans;
	string s;

	scanf("%d%d", &n, &p);
	cin >> s;

	if (p == 2) {
		ans = 0;
		for (i = 0; i < n; i++) {
			if ((s[i] - '0') % 2 == 0) {
				ans += i + 1;
			}
		}
		printf("%lld\n", ans);
		return 0;
	}

	if (p == 5) {
		ans = 0;
		for (i = 0; i < n; i++) {
			if ((s[i] - '0') % 5 == 0) {
				ans += i + 1;
			}
		}
		printf("%lld\n", ans);
		return 0;
	}

	r = 0;
	dd = 1;
	for (i = n - 1; i >= 0; i--) {
		r = (r + (s[i] - '0') * dd % p) % p;
		dd = dd * 10 % p;
		k[i] = r;
	}

	mr[0] = 1;
	for (i = 0; i < n; i++) {
		mr[k[i]]++;
	}

	ans = 0;
	for (i = 0; i < p; i++) {
		ans += mr[i] * (mr[i] - 1) / 2;
	}

	printf("%lld\n", ans);

	return 0;
}
