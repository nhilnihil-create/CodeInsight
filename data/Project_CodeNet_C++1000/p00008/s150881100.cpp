#define scanf_s scanf
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;
#define MAX 20
int main(void)
{
	int n, cou;
	int i = 0, j = 0, l = 0, k = 0;
	while (scanf_s("%d", &n) != EOF) {
		for (int i = 0; i <= 9 && i <= n; ++i) {
			for (int j = 0; j <= 9 && i + j <= n; ++j) {
				for (int l = 0; l <= 9 && i + j + l <= n; ++l) {
					for (int k = 0; k <= 9 && i + j + l + k <= n; ++k) {
						if (i + j + l + k == n) ++cou;
					}
				}
			}
		}
		printf("%d\n", cou);
		cou = 0;
	}
}