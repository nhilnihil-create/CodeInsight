#include <stdio.h>
int main()
{
	int nyawa, serang;
	
	scanf("%d %d",&nyawa, &serang);
 
	printf("%d\n", nyawa%serang == 0 ? (nyawa/serang) : (nyawa/serang)+1);
 
	return 0;
}