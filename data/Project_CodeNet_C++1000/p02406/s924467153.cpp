#include <cstdio>

int main()
{
	int n, x, k;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		x = i;
		k = 0;
		if ((x % 3) == 0) printf(" %d", i);
		else {
			while (x){
				if((x % 10) == 3) k += 1;
				x /= 10;
			}
			if (k) printf(" %d", i);
		}
	}

	printf("\n");

	return 0;
}