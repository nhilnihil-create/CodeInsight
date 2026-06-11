#include<stdio.h>

int main(){
	
	int k;
	k>=1 && k<=100;
	int x;
	x>=1 && x<=100000;
	scanf("%d %d",&k,&x);
	
	if(k * 500>=x){
		printf("Yes");
	}
	else if(k * 500<x){
		printf("No");
	}
	
	
	
	return 0;
}