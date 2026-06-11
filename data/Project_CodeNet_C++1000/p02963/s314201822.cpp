#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxx = 1e5 + 7;
const int Inf = 1 << 30;
const ll INF = 1ll << 60;
ll s;
int a, b, c, d;

int main() {
	scanf("%lld", &s);
	// 定一顶点在(0, 0), 构造向量(a, b)和(c, d)
	// 叉积求面积: s = ad - bc
	a = d = (int)sqrt(s);
	while(s > 1ll * a * d) {
		if(a < d) a++;
		else d++;
	}
	ll chk = 1ll * a * d - s;
	for(int i = 1; i <= sqrt(chk); i++) {
		if(!(chk % i)) {
			if(i <= 1e9 && chk / i <= 1e9) {
				b = i;
				c = chk / i;
				break;
			}
		}
	}
	printf("0 0 %d %d %d %d\n", a, b, c, d);
	return 0;
}