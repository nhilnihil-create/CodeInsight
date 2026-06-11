#include <stdio.h>

int main (){
	int L, R, d;
	int sum = 0;

	scanf ("%d %d %d", &L, &R, &d);
	
	for (int i = L ; i <= R ; i++){
		if (i % d == 0){
			sum++;
		}
	}
	printf ("%d", sum);
	return 0;
}