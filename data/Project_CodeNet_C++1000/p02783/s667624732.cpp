#include <stdio.h>
int main(){
	int nyawa,pukul;
	scanf("%d %d" , &nyawa, &pukul);
	printf("%d" , nyawa%pukul==0? nyawa/pukul : (nyawa/pukul)+1);
	
	return 0;
}