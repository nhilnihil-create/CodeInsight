#include<stdio.h>
int main(){
	char nama[5];
	
	scanf("%s", nama);
	
	if(nama[1] == 'B'){
		printf("ARC");
	} else if (nama[1] == 'R'){
		printf("ABC");
	} else {
	}
	
	return 0;
}