#include<stdio.h>
int main(){
	char x[5];
	char result;
	scanf("%s", &x);
	result = x[1];
	switch(result){
		case 'B':
			printf("ARC");
			break;
		case 'R':
			printf("ABC");
			break;
}
	return 0;
}