#include <stdio.h>
int main(){
	char input[4];
	scanf("%s", &input);//input 100-999
	
	if(input[0]=='7'||input[1]=='7'||input[2]=='7'){
		puts("Yes");
	}
	else{
		puts("No");
	}
	return 0;
}