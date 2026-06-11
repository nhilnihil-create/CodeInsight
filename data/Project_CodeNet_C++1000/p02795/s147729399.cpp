#include <stdio.h>

int main (){
 
 int h, w, n;
 scanf("%d %d %d", &h, &w, &n);
 
 int sum;
 
 	if(h>=w) 
 	{
        if(n%h == 0) 
		{
            sum = n/h;
        } 
		
		else 
		{
            sum = n/h+1;
        }
 	} 
 		
	else 
	{
        if(n%w == 0) 
		{
            sum = n/w;
        } 
		
		else 
		{
            sum = n/w+1;
        }
    }
 	 printf("%d", sum);
 
 return 0;
}