#include<stdio.h>
int main (){
	int nyawaa;
	int damagee;
	int serangann;
	
	1<=nyawaa<=10000;
	1<=damagee<=10000;
	
	scanf("%d %d", &nyawaa, &damagee);
	
	serangann = nyawaa/damagee;
		
	nyawaa%damagee==0 ? printf("%d", serangann) : printf("%d", serangann+1);
	
	
	return 0;
}