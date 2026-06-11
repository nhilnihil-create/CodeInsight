#include <stdio.h>

int main() {
	int n, ans = 0;
	scanf("%d", &n);
	char str[n + 1];
	scanf("%s", str);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				int idx = 0;
				for (int l = 0; l < n; l++) {
					int pos[] = {i, j, k};
					if (str[l] - '0' == pos[idx]) {
						idx++;
					}
					if (idx == 3) {
						ans++;
						break;
					}
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}