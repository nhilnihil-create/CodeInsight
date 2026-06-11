#include<stdio.h>
main(){
	int W,H,x,y,r;
	int left,right,top,bottom;
	scanf("%d %d %d %d %d",&W,&H,&x,&y,&r);

	left = x - r;
	right = x + r;
	top = y + r;
	bottom = y - r;

	if(left >= 0 && right <= W && top <= H && bottom >= 0){
		printf("Yes\n");
	}
	else {
		printf("No\n");
	}
	return 0;
}