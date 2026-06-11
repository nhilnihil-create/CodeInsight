#include<stdio.h>

int main(){
	int l,r,n,x=0;
	scanf("%d%d%d", &l, &r, &n);
	for (int i=l ; i<=r ; i++){
		if (i%n==0){
			x++;
		}
	}
	printf("%d\n", x);
	return 0;
}