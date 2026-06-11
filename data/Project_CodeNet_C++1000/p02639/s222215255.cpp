#include <stdio.h>

int main(){

	int x[6],y;	for(int i=1; i<=5; i++){

		scanf("%d",&x[i]);

		if(x[i]==0) y=i;

	}

	printf("%d",y);

	return 0;

}