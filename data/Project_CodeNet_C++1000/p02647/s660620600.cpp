#include <cstdio>
#include <memory.h>
#include <algorithm>
using namespace std;

typedef long long ll;
ll bulb[300010];
ll bkt[300010];

ll operate(int n) {
	memset(bkt, 0, sizeof bkt);
	for (int i = 0; i < n; ++i) {
		ll op1 = i - bulb[i];
		ll op2 = i + bulb[i];
		if (op1 < 0) op1 = 0;
		++bkt[op1];
		if (op2 >= n) op2 = n - 1;
		--bkt[op2 + 1];
	}
	bulb[0] = bkt[0];
	for (int i = 1; i < n; ++i)
		bulb[i] = bulb[i - 1] + bkt[i];
	return *min_element(bulb, bulb + n);
}

int main() {
	int n, k, i;
	scanf("%d%d", &n, &k);
	for (i = 0; i < n; ++i)
		scanf("%lld", bulb + i);
	for (i = 0; i < k; ++i)
		if (operate(n) >= n)
			break;
	for (int i = 0; i < n; ++i)
		printf("%lld%c", bulb[i], " \n"[i == n - 1]);
	return 0;
}

