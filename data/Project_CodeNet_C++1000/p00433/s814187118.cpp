#include <stdio.h>

main()
{
	int a,b,c,d;
	scanf("%d %d %d %d", &a,&b,&c,&d);
	int e,f,g,h;
	scanf("%d %d %d %d", &e,&f,&g,&h);
	int S,T;
	S = a + b + c + d;
	T = e + f + g + h;
	if (S>T) printf("%d\n",S);
	else	 printf("%d\n",T);
}