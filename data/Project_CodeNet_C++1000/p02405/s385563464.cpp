#include<cstdio>
using namespace std;
int main(void)
{
	int i,j,h,w,flg,k;
	scanf("%d %d",&h,&w);
	while(!(h==0 && w==0)){
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){	
				if((i+j)%2==1) printf(".");
				else printf("#");
			}
			printf("\n");
		}
		scanf("%d %d",&h,&w);
		printf("\n");
	}
	return 0;
}