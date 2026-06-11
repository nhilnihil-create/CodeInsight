#include <bits/stdc++.h>

const int MAX_N = int(1e5) + 10;
const int INF = 0x3f3f3f3f;

int n, tot;
int a[MAX_N], cnt[5], val[5];

int main() {
	scanf("%d", &n);
	bool flag = false;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", a + i);
		flag |= (a[i] != 0);
	}
	if (!flag) {
		puts("Yes");
		return 0;
	}

	std::sort(a + 1, a + n + 1);
	a[0] = INF;
	for (int i = 1; i <= n; ++i) {
		if (a[i] != a[i - 1]) {
			++tot;
			cnt[tot] = 1;
			val[tot] = a[i];
		} else ++cnt[tot];
		if (tot > 3) {
			puts("No");
			return 0;
		}
	}

	if (n % 3 == 0) {
		if (tot == 3) {
			if ((val[1] ^ val[2] ^ val[3]) == 0 && cnt[1] == n / 3 && cnt[2] == n / 3)
				puts("Yes");
			else
				puts("No");
		} else if (tot == 2) {
			if (val[1] == 0 && cnt[1] == n / 3) {
				puts("Yes");
			} else {
				puts("No");
			}
		} else puts("No");
	} else {
		puts("No");
	}
}