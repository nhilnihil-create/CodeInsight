#include <stdio.h>

#define COINNUM 6
#define PAY 1000

int main(void){
	const int coins[COINNUM] = {500, 100, 50, 10, 5, 1};
	int price;
	int back;
	int num;
	
	while (scanf("%d", &price), price){
		back = PAY - price;
		num = 0;
		for (int i=0; i<COINNUM; i++){
			while (back >= coins[i]){
				num++;
				back -= coins[i];
	//			printf("%d, ", coins[i]);
			}
		}
		printf("%d\n", num);
	}
	return 0;
}