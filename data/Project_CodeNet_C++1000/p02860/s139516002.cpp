#include<stdio.h>

int main(){
	int input;
	scanf("%d", &input);
	char kata[input+1];
	scanf("%s", &kata);
	if(input%2==1){
		puts("No");
	}
	else {
		int flag = 1;
		for (int i=0;i<input/2;i++){
			if (kata[i] != kata[i+input/2]){
				flag=0;
			}
		}
		if (flag){
			puts("Yes");
		}
		else {
			puts("No");
		}
	}
	
	return 0;
}