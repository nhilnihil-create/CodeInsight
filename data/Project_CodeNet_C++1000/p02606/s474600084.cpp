#include <stdio.h>

int main() {
	int X, Y, Z;
	
	scanf("%d %d %d", &X, &Y, &Z);
	
	int num = 0;
	for(int i = X; i <= Y; i++){
		if(i % Z == 0) {
			num++;
		}
	} 
	printf("%d\n", num);
	return 0;
}