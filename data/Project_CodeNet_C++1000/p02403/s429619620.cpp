#include<stdio.h>
int main(){
    int a,b,x,y;
	while(1){
		scanf("%d %d",&x,&y);
		if(x==0&&y==0)break;
		for(b=1;b<=x;b++){
		    for(a=1;a<=y;a++){
			    printf("#");
		    }
			printf("\n");
		}
		printf("\n");
	}
			
	return 0;
}