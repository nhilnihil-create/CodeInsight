#include <stdio.h>

#define MAX 5000

int main(void)
{
	int i, j;
	int num[MAX];
	int n;
	int max;
	int sum_ij;
	int max_i;
	while (1) {
		scanf("%d", &n);
		if (n == 0) {
			break;
		}
		for (i = 0; i < n; i++) {
            scanf("%d",&num[i]);
        }
		max=-100000;
        for (i = 0; i < n; i++) {
        	max_i = sum_ij = num[i];
        	for (j = i + 1; j < n; j++) {
        		sum_ij += num[j];
                if (sum_ij > max_i) {
                    max_i = sum_ij;
                }
            }
            if (max_i > max) {
                max = max_i;
            }
        }

        printf("%d\n", max);
	}
	return 0;
}