#include<stdio.h>
#include<math.h>
#include<algorithm>

int main()
{
	int m, n;
	m = 1;
	n = 1;
	while (m <= 9) {
		while (n <= 9) {
			printf("%dx%d=%d\n", m, n,  m * n);
			n++;
		}
		n = 1;
		m++;
	}
    return 0;
}