#include<stdio.h>

int main(void){
int H,W,i,I,j;
for(j=0;j<10000;j++){
	scanf("%d %d",&H,&W);
	if(H!=0){
	for(i=0;i<H;i++){
		for(I=0;I<W;I++){
			printf("#");
		}
		printf("\n");
	}
	printf("\n");
}else{
	break;
}
}
return 0;

}
