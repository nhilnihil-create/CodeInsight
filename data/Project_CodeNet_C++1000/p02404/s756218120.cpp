#include<stdio.h>
int main(){
	int baris, kolom;
	for(int i=0; ; i++){
		scanf("%d %d", &baris, &kolom);
		if(baris==0 && kolom == 0){
			break;
		}
		else{
			for(int j=0; j<baris; j++){
				for(int k=0; k<kolom; k++){
					if(j==0||j==baris-1||k==0||k==kolom-1)printf("#");
					else printf(".");
				}
				printf("\n");
			}
			printf("\n");
		}
	}
}
