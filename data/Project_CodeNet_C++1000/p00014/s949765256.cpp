#include "stdio.h"
#include "math.h"

int main()
{
	int d, x;

	while(scanf("%d", &d) != EOF){
		x = 0;

		for(int i = 0; i < 600; i += d)	x += (d * pow(i, 2.0));

		printf("%d\n", x);
	}

	return 0;
}