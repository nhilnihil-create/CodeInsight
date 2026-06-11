#include <stdio.h>

int main (){
	int n, m;
	scanf ("%d %d", &n, &m);
	int total = (n-1)*n/2 + (m-1)*m/2;
	printf ("%d\n", total);
return 0;
}