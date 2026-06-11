#include <stdio.h>

int main(void){
	int N = 3000;
	int a;
	int b;
	int c;
	int counter;

	scanf("%d %d %d",&a,&b,&c);
	for(int i=a; i <= b; i++){
		if(c%i==0)
		counter++;
}
	printf("%d\n", counter);

	return 0;
}
