#include <stdio.h>
int main (){
	int darah;
	int damage;
	int total;
	int bagi;
	scanf ("%d %d", &darah, &damage);
	total = darah % damage;
	bagi = darah / damage;
	total > 0 ? printf ("%d", bagi + 1) : printf ("%d", bagi);
	return 0;
}