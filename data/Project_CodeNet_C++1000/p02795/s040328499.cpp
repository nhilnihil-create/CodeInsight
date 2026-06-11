#include <stdio.h>
int main(){
	
	int h,w,n,bank = 0;
	scanf("%d %d %d" , &h, &w, &n);
	
	while (n > 0){
		
		if(h > w){
			n -= h;
		}
		else{
			n -= w;
		}
		bank++;
	}
	
	printf("%d" , bank);
	
	
	return 0;
}