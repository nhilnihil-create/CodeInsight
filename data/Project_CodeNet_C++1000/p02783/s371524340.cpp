#include<stdio.h>
int main(){
	int nyawa, pukul;
	scanf("%d %d", &nyawa,&pukul);
	int mati = nyawa / pukul;
	nyawa % pukul == 0 ? printf("%d", mati) : printf("%d", mati + 1);
	
	return 0;
}