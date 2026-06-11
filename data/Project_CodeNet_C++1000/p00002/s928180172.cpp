#include<stdio.h>
#include<string.h>

int main(){
	int a,b;
	char str[8];

    while(scanf("%d %d",&a,&b) != EOF){
		sprintf(str, "%d", a+b);
		printf("%lu\n", strlen(str));
	}

	return 0;
}