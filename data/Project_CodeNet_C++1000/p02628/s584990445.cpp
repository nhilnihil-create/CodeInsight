#include <cstdio>
#include <algorithm>
#define maxn 1005
using namespace std;

int a[maxn];

int main(int argc, char** argv)
{
	int n, k, sum = 0;
	scanf("%d%d", &n, &k);
	for(int i=0; i<n; i++)
		scanf("%d", a + i);
	sort(a, a + n);
	for(int i=0; i<k; i++)
		sum += a[i];
	printf("%d\n", sum);
return 0;
}