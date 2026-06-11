#include <stdio.h>
#include <string.h>

int main(){
	char contest[450];
	scanf("%s",contest);
	if (contest[1]=='B'){
		contest[1]='R';
		printf("%s\n",contest);
	}
	else if (contest [1]=='R'){
		contest[1]='B';
		printf("%s\n",contest);
	}
	return 0;
}