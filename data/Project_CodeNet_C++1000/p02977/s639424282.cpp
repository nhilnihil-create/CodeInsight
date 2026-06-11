#include <bits/stdc++.h>
#define lg2 std::__lg
#define EB emplace_back

typedef std::pair <int, int> pr;

int n;
std::vector <pr> E;
inline void link(int x, int y) {E.EB(std::minmax(x, y));}
int main() {
	int i, u, v;
	scanf("%d", &n);
	if (n & (n - 1)) puts("Yes");
	else return puts("No"), 0;
	link(n + 1, n + 2);
	for (i = 2; i < n; i += 2) link(1, i), link(1, i + 1), link(i, i + n + 1), link(i + 1, i + n);
	if (!(n & 1)) u = 1 << lg2(n + 1), v = (n + 1) & ~u, link(u, 2 * n), link(v, n);
	std::sort(E.begin(), E.end());
	for (const pr &e : E) printf("%d %d\n", e.first, e.second);
	return 0;
}
