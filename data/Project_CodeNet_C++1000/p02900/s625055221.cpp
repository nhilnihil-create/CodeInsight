#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;
#define N 100009
#define LL long long
#define INF 0x7fffffff
#define mymin(x,y) (x>=y?y:x)
#define mymax(x,y) (x>=y?x:y)
LL gcd(LL a, LL b) {
	if (!a) return b;
	if (!b) return a;
	if (a > b) return gcd(a % b, b);
	return gcd(a, b % a);
}
int main() {
	std::ios::sync_with_stdio(0); std::cin.tie(0);
	LL a, b;
	cin >> a >> b;
	LL n = gcd(a, b);
	if (n == 1) {
		cout << 1;
		return 0;
	}
	LL p = 2;
	LL ans = 0;
	while (p < 1e6 && n != 1) {
		if (!(n % p)) {
			ans++;
			while (!(n % p)) {
				n /= p;
			}
		}
		p++;
	}
	if (!ans) {
		cout << 2;
		return 0;
	}
	if (n > 1e6) ans++;
	cout << ans + 1;
	return 0;
}