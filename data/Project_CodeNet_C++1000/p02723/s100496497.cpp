#include <stdio.h>

int main(){
	char kopi[450];
	scanf("%s",kopi);
	if (kopi[2] == kopi [3] && kopi[4] == kopi [5]){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}
