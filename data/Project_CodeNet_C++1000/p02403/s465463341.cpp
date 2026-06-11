#include<stdio.h>
int main()
{
	int h,w;
	scanf("%d %d",&h,&w);
		while(1){
			if(h==0&&w==0)break;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++)printf("#");
		printf("\n");
	}
	scanf("%d %d",&h,&w);
	printf("\n");
	}
	return 0;
}