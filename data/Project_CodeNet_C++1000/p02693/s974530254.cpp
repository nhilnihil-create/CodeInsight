#include<stdio.h>

int main()
{
	int T = 0;
	int A, B, K, i;
	scanf("%d", &K);
	getchar();
	scanf("%d %d", &A, &B);
	for(i = A; i <= B; i++)
	{
		if (i%K == 0)
		{
		T++;
		}
	}
		if (T > 0){printf("OK\n");
		}
		else{printf("NG\n");
		}
  	return 0;
}
