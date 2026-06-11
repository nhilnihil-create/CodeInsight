#include<stdio.h>
int main(){
int input, angka1=0, angka2=0, angka3=0;
	
	scanf("%d", &input);
	
	angka1=input/100;
	angka2=(input-(angka1*100))/10;
	angka3=input%10;

	
	if(angka1 == 7 || angka2 == 7){
	printf("Yes\n");
	}
	else if (angka3 == 7){
		printf("Yes\n");
	}
	else{
		puts("No\n");
	}
	
	
return 0;
}