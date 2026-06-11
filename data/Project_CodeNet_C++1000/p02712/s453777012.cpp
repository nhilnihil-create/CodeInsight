#include <stdio.h>
#include <string.h>

int main (){
	long long int input=0;
	long long int output=0;
	scanf("%lld", &input);
	for (int i = 0; i<=input;i++){
		if (i %3 != 0 && i %5 != 0){
			output += i;
		}
	}
	printf("%lld",output);
}