#include<stdio.h>
#include<math.h>
int main(void){
	int h,w,i,i2;
	scanf("%d %d",&h,&w);
	while(h!=0&&w!=0){
		for(i=0;i<h;i++){
			for(i2=0;i2<w;i2++){
				if(i%2==1){
					if(i2%2==1){
						printf("#");
					}
					else{
						printf(".");
					}
				}
				else{
					if(i2%2==1){
						printf(".");
					}
					else{
						printf("#");
					}
				}
			}
			printf("\n");
		}
		printf("\n");
		scanf("%d %d",&h,&w);
	}
	return 0;
}