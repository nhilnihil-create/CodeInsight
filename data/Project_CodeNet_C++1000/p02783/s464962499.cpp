#include <stdio.h>

int main()
{
	int p, q, r;
	scanf("%d %d", &p, &q);
	while (p>0)
   {
       	p = p-q;
		r++;
   }
    
	printf("%d", r);
    return 0;
    

}