#include <cstdio>

int main()
{
	for (int i = 0; i < 9; ++i) {
		for (int j = 0; j < 9; ++j) {
			int a = i + 1;
			int b = j + 1;
			printf("%dx%d=%d\n", a, b, a * b);
		}
	}
    return 0;
}