#include <stdio.h>

int main() {
	// n = even m = odd
	// output even
	int n, m, counter[2] = {0}, sumn = 0, summ = 0;
	scanf ("%d %d", &n, &m);

	//even + even = even
	// odd + odd = odd
	// 3 odd 2 even =  4 ways to make even 0dd1 0dd2 0dd1 0dd3 0dd2 0dd3 even1 even2
	// 4 odd = o1o2 o1o3 o1o4 o2o3o2o4 o3o4
	// 5 odd = n - 1 + n - 2 + n - 3 + n - 4 + n - n
	for (int i = 1; i <= n; i++) {
		sumn += n - i;
	}
	for (int i = 1; i <= m; i++) {
		summ += m - i;
	}
	printf ("%d", sumn + summ);
	return 0;
}