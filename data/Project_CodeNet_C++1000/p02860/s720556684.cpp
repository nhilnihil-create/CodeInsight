#include<stdio.h>
int main()
{
	int N;
	scanf("%d",&N);
	char S[100];
	int total;
	scanf("%s",&S);
		for (int i=0;i< N/2;i++){
    		if (S[i] == S[i + N/2]){
			total++;
			}	
		}
		if (N % 2 == 1) {
        printf("No");
        return 0;
    }

    
    total == N/2 ? printf ("Yes\n") : printf ("No\n");
return 0;
}