#include<stdio.h>
#include<string.h>

int main(){
	
	char a[15];
	char b[15];
	char c[15];
	
	int x, y;
	
	scanf ("%s %s", &a, &b);
	getchar ();
	scanf ("%d %d", &x, &y);
	getchar();
	scanf("%s", &c);
	
	if (strcmp(a,c)==0){
		printf("%d %d", x-1, y);
	}else if (strcmp(b,c)==0){
		printf("%d %d",x,y-1);
	}
	
	return 0;
}