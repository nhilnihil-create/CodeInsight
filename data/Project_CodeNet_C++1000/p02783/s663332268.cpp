#include <stdio.h>

int main(){
	
	int H, A;
	scanf("%d %d", &H, &A);
	printf("%d\n", H%A == 0 ?  (H/A) : (H/A)+1);


	return 0;
}