#include<cstdio>
int main() {
	for (int a = 1; a<= 9; a++) {
		for (int b = 1; b <= 9; b++) {
			printf("%dx%d=%d\n", a, b, a*b);
		}
	}
}