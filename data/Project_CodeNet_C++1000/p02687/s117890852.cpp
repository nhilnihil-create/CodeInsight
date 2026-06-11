#include<stdio.h>
int main (){
	char contest [10];
	
	scanf("%s", &contest);
	
	if(contest[1]=='B'){
		contest [1] = 'R';
	}else if (contest[1]=='R'){
		contest [1]= 'B';
	}
	printf("%s", contest);
	return 0;
}