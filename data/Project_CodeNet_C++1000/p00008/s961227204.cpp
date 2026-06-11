#include <stdio.h>

int main(void) {
	int a,b,c,d,n,i;
	while(scanf("%d",&n) != EOF){
	i = 0;
	for(a = 0; 10 > a; a++){
		for(b = 0; 10 > b; b++){
	for(c = 0; 10 > c; c++){
	for(d = 0; 10 > d; d++){
		if(a+b+c+d == n)i++;
	}	
	}	
	}
	}
	printf("%d\n",i);
	}
	
	return 0;
}