#include<stdio.h>
int main(){

	int a,b;
	for(;;){
	scanf("%d%d",&a,&b);
	if(a==0&&b==0){
		break;
	}
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++){
			if((i+j)%2==1){
				printf(".");
		}else{
		printf("#");
	}
		}printf("\n");
	}
	printf("\n");
	}
	return 0;
}