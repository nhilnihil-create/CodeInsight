#include<stdio.h>
int main(){
    int a,b,c,d,x,y;
	while(1){
		scanf("%d %d",&x,&y);
		if(x==0&&y==0)break;
		for(c=1;c<=y;c++){
		    printf("#");
		}
		printf("\n");
		for(b=3;b<=x;b++){
			printf("#");
		    for(a=3;a<=y;a++){
		    	printf(".");
		    }
			printf("#\n");
		}
		for(d=1;d<=y;d++){
		    printf("#");
		}
		printf("\n\n");
	}
			
	return 0;
}