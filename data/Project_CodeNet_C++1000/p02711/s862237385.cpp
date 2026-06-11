#include <stdio.h>

int main () {
	int angka;
	scanf ("%d", &angka);
	int x = (angka/100);
	int y = (angka - (x*100))/10;
	int z = (angka - ((angka/10)*10));
	if (x == 7 | y == 7 | z == 7) {
		puts ("Yes");
	} else puts ("No");
	
	return 0;
}