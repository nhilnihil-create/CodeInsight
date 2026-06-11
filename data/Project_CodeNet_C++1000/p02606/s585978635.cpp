#include <stdio.h>

int main (){
	int L, R, d;
	int a, b;
	scanf("%d %d %d", &L, &R, &d);
	b = 0;
	
	for ( int i = 1; i < 101; i++){
		a = i * d;
		if ( a <= R && a >= L){
			b++;
		}
	}
	printf("%d", b);
	
	return 0;
}