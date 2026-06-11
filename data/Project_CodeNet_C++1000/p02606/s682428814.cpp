#include <stdio.h>

int main(){
	int l,r,d,count=0;
	scanf("%d %d %d", &l, &r, &d);
	
	for(int j=1; j<=100; j++){
		if(d*j>=l && d*j<=r){
			count++;
		}  
	}	
	
	
	printf("%d\n", count);
	
	return 0;
}