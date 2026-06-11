#include <stdio.h>
#include <math.h>

void sub1(int *hp,int *wp)
{
	int i,j;
	int y;
	int h=*hp;
	int w=*wp;
	int base,min;
	
	base=pow(h,2)+pow(w,2);
	min=(149,2)+pow(150,2);
	for(i=1;i<=149;i++){
		for(j=i+1;j<=150;j++){
			y=pow(i,2)+pow(j,2);
			if(base<=y&&y<min){
				if(base==y){
					if(h<i){
						*hp=i;
						*wp=j;
						min=y;
					}
				}else{
					*hp=i;
					*wp=j;
					min=y;
				}
			}
		}
	}
}
int main(void)
{
	int height,width;
	int len;
	
	while(1){
		scanf("%d %d",&height,&width);
		if(height==0&&width==0)break;
		sub1(&height,&width);
		printf("%d %d\n",height,width);
	}
	return 0;
}
