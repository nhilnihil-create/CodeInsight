#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	scanf ("%d %d", &n, &k);
	for (int i = k - n + 1; i < k + n; i++) printf ("%d ", i);
	puts("");
	return 0;
}