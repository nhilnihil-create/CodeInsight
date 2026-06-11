#include<stdio.h>
using namespace std;

int main(void){
	int n, x;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		x = i;
		if(x % 3 == 0){
			printf(" %d", i);
		} else {
			do{
				if(x % 10 == 3){
					printf(" %d", i);
					break;
				}
				x = x / 10;
			} while(x);
		}
	}
	printf("\n");
	return 0;
}