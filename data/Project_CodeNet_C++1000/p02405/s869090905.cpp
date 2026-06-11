#include<stdio.h>
int main()
{
	int h,w,c1=0,c2=0,m,n;
	scanf("%d %d",&h,&w);
		while(1){
			c1=0;
			c2=0;
			if(h==0&&w==0)break;
			for(int i=0;i<h;i++){
				for(int j=0;j<w;j++){
					m=c1%2;
					n=c2%2;
					if(m==0&&n==0){
						printf("#");
					}
					else if(m==1&&n==0){
						printf(".");
					}
					else if(m==0&&n==1){
						printf(".");
					}
					else
						printf("#");
					c1++;
				}
				c1=0;
				c2++;
				printf("\n");
			}
			printf("\n");
	scanf("%d %d",&h,&w);
	}
	return 0;
}