#include<stdio.h>
int main(){
	int x=0,y=0,i,j;
	for(i=0; i<9; i++){
	y=0;
	++x;
	for(j=0; j<9; j++){
	++y;
	printf("%dx%d=%d\n",x,y,x*y);
	};
	};
}