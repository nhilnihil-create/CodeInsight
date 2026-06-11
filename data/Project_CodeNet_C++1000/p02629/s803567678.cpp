#include<stdio.h>

int main(){
	long long int input;
	char otp[50];
	int index=1;
	scanf("%lld",&input);
	while(input!=0){
		input--;
		char temp = char(input%26) + 'a';
		otp[index] = temp;
		index++;
		input /=26;
	}
	for(int i = index-1;i>=1;i--) printf("%c",otp[i]);
	printf("\n");
	
	return 0;
}