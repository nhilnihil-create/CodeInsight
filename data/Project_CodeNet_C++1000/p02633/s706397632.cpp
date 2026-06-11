#include<cstdio>
using namespace std;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}
int x;
int main() {
	scanf("%d", &x);
	printf("%lld", 1ll * x * 360 / gcd(x, 360) / x);
}