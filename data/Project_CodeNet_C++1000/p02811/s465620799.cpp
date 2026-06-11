#include <stdio.h>
int main(){
	int amount;
	int balance;
	scanf("%d %d", &amount, &balance);
	int results = 500 * amount;
	(balance <= results) ? printf("Yes") : printf("No");
	return 0;
	}
	
