#include <stdio.h>
#include <cmath>
#include <algorithm>

#define NUM 250000

int main(){
	int table[NUM],limit;

	for(int i=0; i < NUM;i++)table[i] = 1;
	table[0] = 0;
	table[1] = 0;

	limit = sqrt(NUM);

	for(int i=2;i<=limit;i++){
		if(table[i] == 1){
			for(int k=2*i;k < NUM; k += i){
				table[k] = 0;
			}
		}
	}

	int n,count,start,finish;

	while(true){
		scanf("%d",&n);
		if(n == 0)break;

		count = 0;

		if(n%2==0){
			start = n+1;
		}else{
			if(n == 1){
				printf("1\n");
				continue;
			}else{
				start = n+2;
			}
		}

		finish = 2*n;

		for(int i=start; i<= finish; i += 2){
			if(table[i] == 1)count++;
		}
		printf("%d\n",count);
	}
	return 0;
}