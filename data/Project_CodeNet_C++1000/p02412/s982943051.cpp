#include <stdio.h>

int main() {
	int n, x;
	int s1, s2, s3;
	int x2, x3;
	int num;

	scanf("%d %d", &n, &x);
	while(n != 0 || x != 0) {
		num = 0;
		//printf("x1: %d\n", x);
		for(s1 = 1; s1 < x / 3 && s1 <= n; s1++) {
			//printf("s1: %d\n", s1);
			x2 = x - s1;
			//printf("x2: %d\n", x2);
			for(s2 = s1 + 1; s2 <= x2 / 2 && s2 <= n; s2++) {
				//printf("s2: %d\n", s2);
				x3 = x2 - s2;
				//printf("x3: %d\n", x3);
				for(s3 = s2 + 1; s3 <= x3 && s3 <= n; s3++) {
					//printf("s3: %d\n", s3);
					if(s1 + s2 + s3 == x) {
						//printf("%d %d %d\n", s1, s2, s3);
						num++;
					}
				}
			}
		}
		printf("%d\n", num);
		scanf("%d %d", &n, &x);
	}
	return 0;
}