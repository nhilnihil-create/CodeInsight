#include<stdio.h>
int main()
{
	int x;
	int i,c=0;
	scanf("%d",&x);
	while(1){
		for(i=1;i<=x;i++){
			if(x%i==0){
				c++;
			}
		}
		if(c==2){
			break;
		}
		else{
			c=0;
			x++;
		}
	}
	printf("%d\n",x);
	return 0;
}