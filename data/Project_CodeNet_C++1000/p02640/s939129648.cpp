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

int x, y;
int main() {
	scanf("%d%d", &x, &y);
	for (int i = 0; i <= x; i++) {
		int j = x - i;
		if (i * 2 + j * 4 == y) {
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}

