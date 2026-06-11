#include <bits/stdc++.h>

using namespace std;

int cnt[2020];
char s[200005];

int main() {
	scanf("%s", s);
	
	int l = strlen(s);
	
	long long res = 0;
	long long cur = 0;
	long long pw = 1;
	
	cnt[0] = 1;
	for (int i = l - 1; i >= 0; i--) {
		cur = (cur + pw * (s[i] - '0')) % 2019;
		pw = (pw * 10) % 2019;
		res += cnt[cur];
		cnt[cur]++;
	}
	
	printf("%lld\n", res);
}
