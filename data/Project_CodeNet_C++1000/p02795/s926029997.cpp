#include <stdio.h>
int main() {
	int baris, kolom, n;
	scanf("%d",&baris);
	scanf("%d",&kolom);
	scanf("%d",&n);
	
	int max;
	baris > kolom ? max = baris : max = kolom;
	
	n % max == 0 ? printf("%d",n/max) : printf("%d",(n/max)+1);
	return 0;
}