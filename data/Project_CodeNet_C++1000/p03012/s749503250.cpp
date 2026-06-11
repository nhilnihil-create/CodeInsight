#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int main(void) {
	int N;
	scanf("%d", &N);
	int W[110];
	int a = 0;
	int b = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d", &W[i]);
		a += W[i];
	}
	int ans = a;
	for (int i = N; i > 0; i--) {
		ans = min(ans, abs(a - b));
		a -= W[i - 1];
		b += W[i - 1];
	}
	printf("%d", ans);

	return 0;
}
