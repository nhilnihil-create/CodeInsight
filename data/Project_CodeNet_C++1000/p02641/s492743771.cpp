#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long llint;

const int maxn = 2e5+10;
const int base = 31337;
const int mod = 1e9+7;
const int inf = 0x3f3f3f3f;
const int logo = 20;
const int off = 1 << logo;
const int treesiz = off << 1;

int n, x;
int niz[maxn];

int main() {
	scanf("%d%d", &x, &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		niz[x] = 1;
	}
	
	int sol = -1;
	for (int i = 0; i < maxn; i++) {
		if (niz[i] == 0) {
			if (sol == -1 || abs(x - sol) > abs(x - i)) sol = i;
		}
	}
	printf("%d", sol);
	return 0;
}

