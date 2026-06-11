#include <stdio.h>
#include <string.h>
int main (){
	char kata[10001];
	int angka;
	scanf ("%d", &angka);
	scanf ("%s", &kata);
	int panjang = strlen(kata);
	for(int i=0;i<panjang;i++){
		if(kata[i]+angka>'Z'){
			kata[i]=kata[i]-(26-angka);
		}else{
			kata[i]+=angka;
		}
	}
	printf ("%s", kata);
}
