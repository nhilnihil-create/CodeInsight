#include<stdio.h>

int main(void){
	int x,i,s;
	s = 0;
	while(1){
		scanf("%d",&x);
		if(x==0){
			break;
		}else{
			i = s + 1;
			s = i;
			printf("Case %d: %d\n",i,x);
		}


	}


	return 0;
}