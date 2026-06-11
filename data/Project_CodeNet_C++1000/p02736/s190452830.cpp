#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[1010000], P[1010000];
char p[1010000];
bool Odd(int K) {
	return P[n-1] == P[K] + P[n-1 - K];
}
int main() {
	int i;
	scanf("%d", &n);
	scanf("%s", p);
	P[0] = 0;
	for (i = 1; i <= n; i++) {
		int t = i;
		P[i] = P[i - 1];
		while (t % 2 == 0)t /= 2, P[i]++;
	}
	int chk = 0;
	for (i = 0; i < n; i++) {
		w[i] = p[i] - '1';
		if (w[i] == 1) {
			chk = 1;
		}
	}
	int ck = 0;
	for (i = 0; i < n; i++) {
		if (Odd(i))ck ^= w[i] % 2;
	}
	if (ck == 1) {
		puts("1");
		return 0;
	}
	if (chk) {
		puts("0");
		return 0;
	}
	for (i = 0; i < n; i++)w[i] /= 2;
	for (i = 0; i < n; i++) {
		if (Odd(i))ck ^= w[i];
	}
	if (ck == 1)puts("2");
	else puts("0");
}