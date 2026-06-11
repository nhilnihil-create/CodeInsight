
#include <stdio.h>
int main(){
	int H;
	int A;
	scanf("%d %d",&H,&A);
	
	int c=H/A;
	if(H%A !=0){
		c++;
	}
	printf("%d",c);
	
	return 0;
}
	