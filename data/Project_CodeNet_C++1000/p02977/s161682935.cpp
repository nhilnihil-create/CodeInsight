#include <bits/stdc++.h>

int n;
int main()
{
	scanf("%d",&n);
	int j = n;
	while((j & 1) == 0) j >>= 1;
	if(j == 1) {
		printf("No\n");
		return 0;
	} else {
		printf("Yes\n");
		printf("%d %d\n", 1, n+2);
		printf("%d %d\n", n+2, 3);
		printf("%d %d\n", 3, n+1);
		printf("%d %d\n", n+1, 2);
		printf("%d %d\n", 2, n+3);
		for(int i = 4;i < n;i += 2) {
			printf("%d %d\n", n+1, i);
			printf("%d %d\n", n+1, i+1);
			printf("%d %d\n", i, n+i+1);
			printf("%d %d\n", i+1, n+i);
		}
		if(n % 2 == 0) {
			for(int j = 2;j < n;++j) if((n^j^1)>=2 && (n^j^1)<n) {
				int a = n^j^1;
				printf("%d %d\n", n, a);
				printf("%d %d\n", 2*n, j);
				break;
			}
		}
	}
}
