#include <stdio.h>

int main ()  {
	char name[5];
	scanf("%s", name);
	if (name[1] == 'B') {
		name[1] = 'R';
	} 
	else if (name[1] == 'R'){
		name[1] = 'B'; 
	} 
	printf("%s\n", name);
	return 0;
}