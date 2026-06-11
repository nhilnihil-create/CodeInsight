#include <stdio.h>
int main (){
	int angka;
	char kata[255];
	int temp =1;
	scanf ("%d", &angka);
	scanf("%s", kata);
	if(angka%2!=0){
		temp=-1;
	}
	for (int i=0;i<angka/2;i++){
		if(kata[i]!=(kata[(angka/2)+i])){
			temp=-1;
		}
		}
	if(temp==1){
		printf("Yes");
	}else if (temp==-1){
		printf ("No");
	}
}
