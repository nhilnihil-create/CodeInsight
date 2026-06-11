#include <stdio.h>

int main (){
	
	int darah;
	int dmg;
	int jumlah;
	int bagi;

	scanf ("%d %d", &darah, &dmg);
	jumlah = darah % dmg;
	bagi = darah / dmg;
	jumlah > 0 ? printf ("%d", bagi + 1) : printf ("%d", bagi);
	
	return 0;
}