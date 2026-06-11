#include<stdio.h>
int main (){
	int H,A,yeet=0;
		scanf("%d",&H);
		scanf("%d",&A);
	while(H > 0)
	{
	H = H - A;
	yeet++;
	
		}
	printf("%d\n",yeet);
	
	return 0;
}