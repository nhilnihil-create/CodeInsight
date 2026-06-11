#include<stdio.h>
int main(void)
{
	int D,T,S,x;
	scanf("%d %d %d",&D,&T,&S);
	x = T*S;
	if(x>=D) {
		printf("Yes\n");
	}
    else{
			printf("No\n");
		}
	return 0;
}