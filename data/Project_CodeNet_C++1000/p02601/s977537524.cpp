#include <cstdio>

int a, b, c, k;

int main()
{
	scanf("%d%d%d%d", &a, &b, &c, &k);
	while(b <= a) b *= 2, --k;
	while(c <= b) c *= 2, --k;
	if(k >= 0) printf("Yes\n");
	else printf("No\n");
	return 0;
}