#include<stdio.h>
int main()
{
	char S[4];	
	scanf("%s",S); 
	int x = 0;
	for(int i = 0; i<3; i++)
	{
		if(S[i] == S[i+1]){
			x = 1;
		}
	} 
	if(x == 1){
		printf("Bad");
	}
	else{
		printf("Good");
	}
}