#include <stdio.h>
#include <string.h>


int main() {
	int HP;
	int Strike;
	
	scanf("%d %d", &HP, &Strike);
	HP % Strike == 0? printf("%d", HP/Strike): printf("%d", HP/Strike+1);
	
	
	return 0;
}