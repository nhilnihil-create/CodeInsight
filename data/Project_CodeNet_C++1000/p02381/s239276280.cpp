#include <cstdio>
#include <cmath>
int main(void) {
	int n, s[1000];


	while (scanf("%d", &n) != EOF) {
		float m = 0, sig = 0;
		if (!n)return 0;
		for (int i = 0; n > i; i++) {
			scanf("%d", &s[i]);
			m += s[i];
		}
		m /= n;
		for (int i = 0; n > i; i++) {
			sig += (s[i] - m)*(s[i] - m);
		}
		printf("%f\n", sqrt(sig / n));
	}
	return 0;
}