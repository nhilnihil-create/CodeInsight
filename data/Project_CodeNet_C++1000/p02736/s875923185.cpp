#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 5;

int N;
char s[MAXN];
int nxt[MAXN];

void load() {
	scanf("%d%s", &N, s);
}

int parity() {
	int res = 0;
	for (int i = 0; i < N - 1; i++)
		if ((N - 2 & i) == i)
			res ^= nxt[i] & 1;
	return res;
}

int solve() {
	bool one = false;
	for (int i = 0; i < N - 1; i++) {
		nxt[i] = abs((int)s[i] - (int)s[i + 1]);
		one |= nxt[i] == 1;
	}
	if (one)
		return parity();
	for (int i = 0; i < N - 1; i++)
		nxt[i] /= 2;
	return 2 * parity();
}

int main() {
	load();
	printf("%d\n", solve());
	return 0;
}