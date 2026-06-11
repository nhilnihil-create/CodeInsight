#include <iostream>
#include <stdio.h>

int i = 1;

int main(){
	while(i <= 9 ){
		int r = 1;
		while(r <= 9){
			int num = i * r;
			printf("%dx%d=%d\n", i, r, num);
			r++;
		}
		i++;
	}
	return 0;
}