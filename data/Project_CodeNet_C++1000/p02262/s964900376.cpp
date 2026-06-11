#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
using namespace std;

static inline void pn(int n)
{
	if (n == 0)
		putchar('0');
	else {

		int i;
		static char buf[20];
		for (i = 0; n; n /= 10, i++)
			buf[i] = n % 10 +'0';
		while (i--)
			putchar(buf[i]);
	}
	putchar('\n');
}

int main()
{
	int n, cnt = 0;

	scanf("%d", &n);

	vector<int> A(n), G;
	for (int &x: A)
		scanf("%d", &x);

	for (int i = 1, x = 1; x <= n; x = (pow(3, ++i) - 1) / 2)
		G.push_back(x);
	reverse(G.begin(), G.end());

	for (int g: G)
		for (auto b = A.begin(), i = b + g, e = A.end(); i != e; i++) {
			int v = *i;
			auto j = i - g;
			for(; j >= b && *j > v; j -= g)
				*(j + g) = *j, cnt++;
			*(j + g) = v;
		}

	pn(G.size());
	for (int &x: G)
		printf("%s%d", (&x == &G[0] ? "" : " "), x);
	putchar('\n');
	pn(cnt);
	for (int x: A) {
		pn(x);
	}
}
