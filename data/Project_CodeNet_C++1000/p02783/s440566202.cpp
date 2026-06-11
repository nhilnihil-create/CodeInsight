#include<stdio.h>
int main()
{
	int H;
	int A;
	scanf("%d %d",&H,&A);
	if(H%A ==0){
		printf("%d",H/A);
	}
	else if (H%A !=0){
		printf("%d",H/A+1);	
	}
	return 0;
}