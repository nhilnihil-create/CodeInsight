#include <stdio.h>
int main (){
	int input, digit1, digit2,digit3;
	scanf("%d",&input);
	
	digit3= input%10;
	digit2= (input%100- input%10)/10;
	digit1= input/100;
	
	if (digit1==7||digit2==7||digit3==7){
		printf("Yes");
	}
	else {
		printf("No");
	}
	return 0;
}