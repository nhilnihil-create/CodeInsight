#include <stdio.h>

int main(){
	char contest[3];
	scanf("%s", contest);
	
	if(contest[1] == 'B'){
		contest[1] = 'R';
	}
	else{
		contest[1] = 'B';
	}
	printf("%s\n", contest);
	return 0;
}