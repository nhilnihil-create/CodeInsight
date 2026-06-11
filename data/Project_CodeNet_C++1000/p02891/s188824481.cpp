#include<bits/stdc++.h>
using namespace std;
const int maxn = 100 + 7;
long long n, k;
char s[maxn];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	scanf("%lld", &k);
	long long fl = 0;
	if(s[1] == s[n]) {
		int p = 1; fl = 1;
		while(s[p] == s[1] && p <= n) ++p;
		if(((p - 1) & 1) == 0) fl = 0;
		if(p == n + 1) {
			long long sum = n * k;
			printf("%lld\n", sum >> 1);
			return 0;
		}
		p = n;
		while(s[p] == s[n] && p) --p;
		if(((n - p) & 1) == 0) fl = 0;
	}
	fl = fl * (k - 1);
	long long ans = 0;
	for (int i = 2; i <= n; ++i) {
		if(s[i] == s[i - 1]) {
			s[i] = 0;
			++ans;
		}
	}
	ans = ans * k + fl;
	printf("%lld\n", ans);
	return 0;
}