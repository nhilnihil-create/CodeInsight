#include <bits/stdc++.h>

const int MAX_N = int(1e6) + 10;

int n;
char s[MAX_N];
int cnt[3];

int main() {
	scanf("%d%s", &n, s);
	bool have_one = false;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '2')
			have_one = true;
		cnt[s[i] - '1'] += ((n - 1) & i) == i;
	}
	if (cnt[1] & 1)
		puts("1");
	else {
		if (!have_one && (cnt[2] & 1))
			puts("2");
		else
			puts("0");
	}
}