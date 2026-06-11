#include<stdio.h>

int main(){
	int baris,kolom,syarat,temp=0;
	scanf("%d %d %d", &baris, &kolom, &syarat);
	if(baris>kolom){
		temp=syarat/baris;
		//printf("temp adalah %d\n", temp);
		if(syarat%baris==0){
			printf("%d\n", temp);
		}
		else printf("%d\n", temp+1);
	}
	else{
		temp=syarat/kolom;
		if(syarat%kolom==0){
			printf("%d\n", temp);
		}
		else printf("%d\n", temp+1);
	}
	return 0;
}