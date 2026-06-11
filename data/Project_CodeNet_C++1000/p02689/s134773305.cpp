#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 100000;
bool bad[N];
int h[N];
int n;
int m;

int main() 
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) scanf("%d", h + i);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		int mn = min(h[a - 1], h[b - 1]);
		if (h[a - 1] == mn) bad[a - 1] = true;
		if (h[b - 1] == mn) bad[b - 1] = true;
	}
	int c = 0;
	for (int i = 0; i < n; ++i) c += !bad[i];
	printf("%d\n", c);
	return 0;
}
