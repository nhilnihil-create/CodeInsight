#include <stdio.h>
int main() {

	int x;
	int y;
	scanf("%d%d", &x,&y);
	
	 
	 
	 if(x%y==0) {
		printf("%d",(x/y));}
		
	 else if(x>y) {
		printf("%d", (x/y)+1);
	}
	
	else if(x<y) {
			printf("%d", 1);
	}


 return 0;
}