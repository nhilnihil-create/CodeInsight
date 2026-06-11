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

int main() {
	for (int i = 1; i <= 5; i++) {
		int x;
		scanf("%d", &x);
		if (x == 0) {
			printf("%d\n", i);
		}
	}
	return 0;
}

