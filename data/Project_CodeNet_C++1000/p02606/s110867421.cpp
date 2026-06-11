#include <stdio.h>

int main(){
	int L, R, D;
	scanf("%d %d %d", &L, &R, &D);
	int c = 0;
	for (int i = L; i <= R; i++){
		if (i%D==0){
		c++;
		}
	}
	printf("%d", c);
	return 0;
}