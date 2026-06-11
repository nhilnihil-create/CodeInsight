#include<stdio.h>

int main(){
	int i;
	int j;
	int h;
	for(i = 1; i<=9;i++){
		for(j =1; j<=9;j++){
			h = i * j;
			printf("%dx%d=%d\n",i,j,h);
		}
	}

}