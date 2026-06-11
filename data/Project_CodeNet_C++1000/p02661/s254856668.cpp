#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 200000;
int a[2][N];

int main() 
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) scanf("%d%d", a[0] + i, a[1] + i);
	sort(a[0], a[0] + n);
	sort(a[1], a[1] + n);
	if (n & 1) printf("%d\n", a[1][n / 2] - a[0][n / 2] + 1);
	else printf("%d\n", a[1][n / 2] + a[1][n / 2 - 1] - a[0][n / 2] - a[0][n / 2 - 1] + 1);
	return 0;
}
