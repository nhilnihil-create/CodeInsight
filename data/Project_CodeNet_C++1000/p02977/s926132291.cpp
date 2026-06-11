#include <bits/stdc++.h>
#define mset(a, b) memset(a, b, sizeof(a))
#define mcpy(a, b) memcpy(a, b, sizeof(a))
using namespace std;
typedef long long LL;

template <typename T> inline void read(T &AKNOI) {
	T x = 0, flag = 1;
	char ch = getchar();
	while (!isdigit(ch)) {
		if (ch == '-') flag = -1;
		ch = getchar();
	}
	while (isdigit(ch)) {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	AKNOI = flag * x;
}

inline void Edge(int u, int v) {
	printf("%d %d\n", u, v);
}

void solve() {
	int n; read(n);
	int x;
	for (x = 1; x < n; x <<= 1);
	if (x == n) {
		printf("No\n"); 
		return;
	}
	
	printf("Yes\n");
	for (int i = 2; i < n; i += 2) {
		Edge(1, i);
		Edge(i, i + 1);
		Edge(1, n + i + 1);
		Edge(n + i + 1, n + i);
	}
	Edge(n + 1, 3);
	
	if (n % 2 == 0) {
		for (int i = 2; i < n; ++i) {
			int j = n ^ i ^ 1;
			if (j != i && 2 <= j && j < n) {
				Edge(n, i + n * (i & 1));
				Edge(n + n, j + n * (j & 1));
				return;
			}
		}
	}
}

int main() {
	solve();
	return 0;
}
