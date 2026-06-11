#include <stdio.h>

int main (){
	int h1, h2, m1, m2, k;
	scanf ("%d %d %d %d %d", &h1, &m1, &h2, &m2, &k);
	int minutes1 = h1*60 + m1, minutes2 = h2*60 + m2;
	int totalMinutes = minutes2 - minutes1;
	printf ("%d\n", totalMinutes - k);
return 0;
}