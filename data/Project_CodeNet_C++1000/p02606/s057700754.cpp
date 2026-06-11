#include <stdio.h>

int main (){	

	int a, b, c, ctr = 0;
	scanf("%d %d %d", &a, &b, &c);
	for(; a<=b; a++ ){
		if(a%c==0) {
			ctr++;
  		}
 	}
	printf("%d\n", ctr);
		return 0;
}