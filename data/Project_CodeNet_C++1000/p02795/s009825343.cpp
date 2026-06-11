#include <stdio.h>

int main() {
	int h, w, n;
	int sum = 0, count = 0;
	scanf ("%d %d %d", &h, &w, &n);
	
		if (h >= w) {
			for (sum; sum < n; sum += h) {
			count++;
			}
		}
		else {
			for (sum; sum < n; sum += w) {
			count++;
			}	
		}
	printf ("%d", count);
	
	return 0;
}