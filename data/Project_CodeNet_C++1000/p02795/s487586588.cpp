#include <stdio.h>

int main() {

	int a, b, n;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &n);
	
	int sum;
	if (a>=b){
		if(n%a==0){
			sum=n/a;
		}
		else{
			sum=(n/a)+1;
		}
	}
	
	else if(b>a){
		if(n%b==0){
			sum=n/b;
		}
		else{
			sum=(n/b)+1;
		}
	}

	printf("%d\n", sum);
	
    return 0;
}