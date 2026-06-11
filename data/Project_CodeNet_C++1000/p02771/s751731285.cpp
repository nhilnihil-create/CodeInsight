#include <stdio.h>

int main (){
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);
	if((A==C&&B==A&&B==C)||(A!=C&&B!=A&&B!=C))
	{
	puts("No"); 
	}
	else 
	{
	puts("Yes");	
	}
return 0;
}