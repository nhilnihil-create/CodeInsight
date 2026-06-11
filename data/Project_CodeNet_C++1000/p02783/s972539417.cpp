#include <stdio.h>

int main() {
	int chi, kougeki, kaunta;
	scanf("%d %d", &chi, &kougeki);
	kaunta = 1;
	chi % kougeki == 0 ? printf("%d", chi/kougeki) : printf("%d", (chi/kougeki)+1);
	
	return 0;
}