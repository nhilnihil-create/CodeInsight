#include <stdio.h>

int main(){
	while(1){
	int n;
	scanf("%d", &n);
	if(n==0) break;	

	int i;
	int x,y;
	x = y = 0;
	for(i=0;i<n;i++){
		int a,b;
		scanf("%d%d", &a, &b);

		if(a>b) x+=a+b;
		else if(a==b) x+=a,y+=b;
		else y+= a+b;
	}
	printf("%d %d\n", x, y);
	}
}