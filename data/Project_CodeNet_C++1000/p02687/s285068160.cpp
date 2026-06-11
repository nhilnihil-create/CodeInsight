#include <stdio.h>

int main(){
	char a[3];
	scanf("%s",a);
	if(a[1]=='B'){
		a[1]='R';
	}
	else{
		a[1]='B';
	}
	printf("%s",a);
	return 0;
}