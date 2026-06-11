#include<stdio.h>

int main(){
	int genap,ganjil;
	scanf("%d %d", &genap, &ganjil);
	int tempGenap=0, tempGanjil=0;
	if(genap>1){
		for(int i=genap-1;i>=1;i--){
		tempGenap+=i;
		}
	}
	if(ganjil>1){
		for(int i=ganjil-1;i>=1;i--){
		tempGanjil+=i;
		}
	}
	printf("%d\n", tempGenap+tempGanjil);
	return 0;
}