#include<stdio.h>

int main(void) {

	for (int i = 1; i <= 9; i++)
	{
		for (int t = 1; t <= 9; t++)
		{
			printf("%dx%d=%d\n", i, t, i*t);
		}
	}
	return 0;
}
