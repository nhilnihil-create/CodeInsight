#include <stdio.h>

int main ()
{
    int a;
	int b;
	int c;
	int d;
    
	scanf("%d", &a);
    scanf("%d %d", &b, &c);
        
	for(b;b<=c;b++)
    {
    	if(b%a==0)
        {
            d++;
        }
    }
    
    if(d!=0)
    {
        printf("OK");
    }
    
	else
    {
        printf("NG");
    }


    return 0;
}