#include <stdio.h>

int main (){
	int n,a,b,sum=0;
	
	scanf ("%d",&n);
	scanf ("%d %d", &a, &b);
	
	for (int i=a; i<=b; i++){
		if (i%n==0){
			sum=1;
		}
	}
	if (sum==1){
		printf ("OK");
	}
	else {
		printf ("NG");
	}
	
	return 0;
}