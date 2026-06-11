#include <stdio.h>

int main(void)
{
	int n;
	int a[10000];

	while (1){
		scanf("%d", &n);
		if (n == 0){
			break;
		}

		for (int i = 0; i < n; i++){
			scanf("%d", a + i);
		}

		int ans = -100000;
		for (int i = 0; i < n; i++){
			int sum = 0;
			for (int j = i; j < n; j++){
				sum += a[j];
				if (ans < sum){
					ans = sum;
				}
			}
		}

		printf("%d\n", ans);
	}
	return (0);
}