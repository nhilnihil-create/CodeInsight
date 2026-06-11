#include <bits/stdc++.h>

using namespace std;
constexpr int NMAX = 1000010;
int vp2(int x) {
	if (x % 2 == 1) return 0;
	else return 1 + vp2(x / 2);
}
int vp2fac[NMAX];
int vp2binom(int n, int r) {
	return vp2fac[n] - vp2fac[r] - vp2fac[n - r];
}
char initRow[NMAX];
int simula[NMAX];
int main() {
	vp2fac[0] = 0;
	for (int i = 1; i < NMAX; ++i) vp2fac[i] = vp2fac[i - 1] + vp2(i);
	int n; scanf("%d", &n);
	scanf("%s", initRow);
	bool hasOne = false; // this refers to the shifted-down version
	for (int i = 0; i < n; ++i) if (initRow[i] == '2') hasOne = true;
	if (!hasOne) for (int i = 0; i < n; ++i) simula[i] = (initRow[i] - '1') / 2;
	else for (int i = 0; i < n; ++i) simula[i] = 1 - abs(initRow[i] - '2');
	int tans = 0;
	for (int i = 0; i < n; ++i) tans = (tans + (vp2binom(n - 1, i) ? 0 : 1) * simula[i]) % 2;
	if (hasOne) printf("%d\n", tans == 0 ? 0 : 1);
	else printf("%d\n", tans == 0 ? 0 : 2);
	return 0;
}
