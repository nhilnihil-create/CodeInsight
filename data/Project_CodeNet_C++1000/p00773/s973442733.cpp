#include <stdio.h>
#include <stdlib.h>

int calc_tax(int p, int t){
	return (int)(p*(100+t)/100);
}

int main(){
	int x, y, sum;
	int a, b;
	int max = 0, s;
	while(1){
		scanf("%d %d %d", &x, &y, &sum);
		if(x == 0) break;
		for(a = 1; a <= sum/2; a++){
			for(b = a; a+b <= sum; b++){
				if(calc_tax(a, x) + calc_tax(b, x) == sum){
					s = calc_tax(a, y) + calc_tax(b, y);
					if(max < s) max = s;
				}
			}
		}
		printf("%d\n", max);
		max = 0;
	}
	return 0;
}