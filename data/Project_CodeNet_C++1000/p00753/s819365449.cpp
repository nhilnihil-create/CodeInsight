#include <stdio.h>
#include <math.h>

int h[2*123456];
int n;

int main()
{
	int i,j;
	int count = 0;
	while(1){
		scanf("%d", &n);
		if(n == 0) break;
		if(n == 1){
			printf("%d\n", 1);
			continue;
		}
		for (i = 1; i < 2*n;i++)
		{
			h[i] = i;
		}
		h[0] = 0;
		h[1] = 0;
		i = 2;
		while(i < sqrt(2*n)){
			for(j = 2*i; j < 2*n; j += i){
				h[j] = 0;
			}
			j = i+1;
			while(h[j] == 0) j++;
			i = h[j];
		}
		count = 0;
		for(i = n+1; i < 2*n; i++){
			if(h[i] != 0) count++;
		}
		printf("%d\n", count);
	}
	return 0;
}