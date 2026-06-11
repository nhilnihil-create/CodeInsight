#include <stdio.h>
#include <string.h>

int main(){
	int H, A, mod, attack;
	scanf("%d %d", &H, &A);
	getchar();
	
	mod = H % A;
	attack = H / A;
	mod == 0 ? printf("%d", attack) : printf("%d", attack+1); 
	
	return 0;
}