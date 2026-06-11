#include <stdio.h>

int main(){
	
int N,M;
int A,B,X,i,Y;		//4 5
scanf("%d %d", &N, &M);

A=1;
X=0;
for(i=2;i<=N; i++){
	
	X=X+A;
	A++;
}
A=1;
Y=0;
for(i=2;i<=M; i++){
	
	Y=Y+A;
	A++;
}
printf("%d", X+Y);

	return 0;
	
}