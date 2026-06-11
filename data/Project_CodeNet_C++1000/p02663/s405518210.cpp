#include <stdio.h>

int main() {
	int h1, m1, h2, m2, k;
	scanf("%d %d %d %d %d",&h1,&m1,&h2,&m2,&k);
	if (m1 > m2)
	{
		h2--;
		m2 += 60;
	}
	int duration = (h2-h1)*60 + (m2-m1);
	duration > k ? printf("%d\n",duration-k) : printf("0\n");
	return 0;
}

