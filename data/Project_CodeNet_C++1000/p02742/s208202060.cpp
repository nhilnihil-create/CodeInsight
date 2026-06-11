#include<stdio.h>
#include<math.h>
int main()
{
	int r,c;
	long long d;
	while(~scanf("%d %d", &r, &c))
	{
		d = r==1||c==1? 1: (((long long)c*r)+1)/2;
		printf("%lld\n", d);
	}
	return 0;
}