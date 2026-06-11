#include <bits/stdc++.h>

using namespace std;


int N, a[1000010], p[1000010], sum[1000010], eo;

char s[1000010];

bool flag = false;


int main() {
	cin >> N;
	scanf("%s", s);
	for (int i = 0; i < N; i++) a[i] = s[i] - '1', flag |= (a[i] == 1);
	if (!flag) {
		for (int i = 0; i < N; i++) a[i] >>= 1;
	}
	for (int i = 1; i < N; i++) {
		p[i] = ((i & 1) ? 0 : p[i >> 1] + 1);
		sum[i] = sum[i - 1] + p[i];
		//cout << sum[i] << "--------\n";
	}
	for (int i = 0; i < N; i++) if (a[i] & 1) eo ^= ((sum[N - 1] - sum[i] - sum[N - 1 - i]) == 0);
	if (eo & 1) return puts(flag ? "1" : "2") & 0;
	return puts("0") & 0;
} 
