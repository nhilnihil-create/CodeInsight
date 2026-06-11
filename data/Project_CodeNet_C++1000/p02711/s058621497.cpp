#include <stdio.h>

int main (){
	int a;
	int cek=0;
	scanf("%d", &a);
	for (int i=0; i<3; i++){
		if (a%10==7|| a/100==7|| (a-(a/100)*100)/10 ==7){
			cek++;
		}
	}
	if (cek>0){
		printf("Yes");
	}
	else {
		printf("No");
	}
	return 0;
}