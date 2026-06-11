#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	vector<int> p(n, 0), l(n, 0);
	vector<ll> c(n, 0), s(n, 0);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
		p[i]--;
	}
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &c[i]);
	}
	for (int i = 0; i < n; ++i) {
		if (l[i] == 0) {
			int C = 1;
			ll S = c[i];
			for (int j = p[i]; j != i; S += c[j], ++C, j = p[j]);
			l[i] = C;
			s[i] = S;
			for (int j = p[i]; j != i; l[j] = C, s[j] = S, j = p[j]);
		}
	}
	ll a = ll(-1e18);
	for (int i = 0; i < n; ++i) {
		if (k < l[i]) {
			ll tmp = 0;
			for (int j = p[i], m = k; m; --m, j = p[j]) {
				tmp += c[j];
				a = max(a, tmp);
			}
		}
		else if (s[i] > 0) {
			ll tmp = s[i]*ll(k/l[i]-1);
			a = max(a, tmp);
			for (int j = p[i], m = l[i]+k%l[i]; m; --m, j = p[j]) {
				tmp += c[j];
				a = max(a, tmp);
			}
		}
		else {
			ll tmp = 0;
			for (int j = p[i], m = l[i]; m; --m, j = p[j]) {
				tmp += c[j];
				a = max(a, tmp);
			}
		}
	}
	printf("%lld\n", a);
}