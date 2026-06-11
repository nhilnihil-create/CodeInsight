#include <stdio.h>
int main ()
{
	int H,A,J,result;
	scanf("%d", &H);
	scanf("%d", &A);
	if(H%A==0){
		J=H/A;
		printf("%d",J);
	}
	else{
		result=(H/A)+1;
		printf("%d",result);
	}
return 0;
}