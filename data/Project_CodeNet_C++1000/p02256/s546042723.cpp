#include <stdio.h>

int main(int argc, char* argv[])
{
	int x = 0, y = 0;
	scanf("%d %d", &x, &y);

	if (x > y) {
		int tmp = x;
		x = y;
		y = tmp;
	}

	bool loop = true;
	while (loop) {
		int mod = x % y;
		if (mod == 0) {
			break;
		} else {
			x = y;
			y = mod;
		}
	}
	printf("%d\r\n", y);

	return 0;
}