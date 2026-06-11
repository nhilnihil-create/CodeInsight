#include<stdio.h>

int main(){
	int x;
	int y;
	scanf ("%d %d",&x,&y);
	int IR = 100*(10-x);
	
	int IRT = y+ IR;
	if(x<=10){
			printf("%d",IRT);
	}
	else {
		printf("%d",y);
	}
	
	
	return 0;
}