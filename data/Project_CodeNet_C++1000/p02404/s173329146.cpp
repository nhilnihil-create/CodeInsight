#include <cstdio>
int main(){
	int H,W;
	while(1){
		scanf("%d %d",&H,&W);
		if(!W&&!H){break;}
		for(int i=0;i<H;i++){
			if(!i||!(i-H+1)){
				for(int j=0;j<W;j++){
					putchar('#');
				}
			}
			else{
				for(int j=0;j<W;j++){
					if(!j||!(j-W+1))putchar('#');
					else putchar('.');
				}
			}
			putchar('\n');
		}
		putchar('\n');
	}
}