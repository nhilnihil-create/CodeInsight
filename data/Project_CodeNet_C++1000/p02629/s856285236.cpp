#include<stdio.h>
 
int main()
{
    long long int b;
    scanf("%lld",&b);
    int i = 0;
    char str[100];
    
    while(b > 0)
	{
        int check = b % 26;
        
        if (check == 0)
		{
            str[i++] = 'z';
            b = (b/26) - 1;
        }
		else
		{
            str[i++] = (check - 1) + 'a';
            b /= 26;
        }
    }
    str[i] = '\0';
    
	int j;
    for(j = i - 1; j >= 0; j--)
	{
        printf("%c", str[j]);
    }
    
    return 0;
}