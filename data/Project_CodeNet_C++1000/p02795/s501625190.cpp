#include <stdio.h>

int main() {
	int Zx, Xy, Yz, z = 0, x = 0;
	scanf("%d %d %d", &Zx, &Xy, &Yz);
	while (Yz > z) {
		if (Zx < Xy) {
			z += Xy;
			x++;
		} else {
			z+= Zx;
			x++;
		}
	}
	printf("%d", x);
	return 0;
}