#include<stdio.h>

int main()
{
	int tc, num[100000], count=0, i, save, acd[100000];

	scanf("%d", &tc);

	for(i = 1; i<= tc; i++)
	{
		scanf("%d", &num[i]);
		acd[i] = i;
	}
	for(i = 1; i <= tc; i++)
	{
		if(acd[i] == num[i])
            save = 1;
        else
            count++;
	}
    if(count <= 2 && save == 1)
        printf("YES\n");
    else
        printf("NO\n");


	return 0;
}