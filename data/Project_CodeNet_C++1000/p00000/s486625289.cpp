#include <stdio.h>

#define rep(i,n) for(int i = 0; i < n; i++)

int main()
{
	rep(i, 9) rep(ii, 9)
	{
		printf("%dx%d=%d\n", i + 1, ii + 1, (i + 1) * (ii + 1));
	}
	return 0;
}