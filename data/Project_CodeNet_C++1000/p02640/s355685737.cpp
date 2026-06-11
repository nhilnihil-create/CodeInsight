#include <stdio.h>

int x,y,c,t;

int main(){

	scanf("%d%d", &x,&y);	for(t=0; t<=x; t++){

		c=x-t;

		if(4*t+2*c==y){

		printf("Yes\n");

		return 0;

	}

	}

	printf("No\n");

	return 0;

}