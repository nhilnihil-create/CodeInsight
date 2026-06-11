#include<stdio.h>
int main(){
	int k, x, m;
	scanf("%d %d", &k, &x);
	k>=1;
	k<=100;
	x>=1;
	x<=100000;
	
	m = k*500;
	if(m>x-1){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	
	return 0;
}