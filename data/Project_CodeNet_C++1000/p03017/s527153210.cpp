#include <bits/stdc++.h>
using namespace std;
#define db(x) cerr << #x << "=" << x << endl
#define db2(x, y) cerr << #x << "=" << x << "," << #y << "=" << y << endl
#define db3(x, y, z) cerr << #x << "=" << x << "," << #y << "=" << y << "," << #z << "=" << z << endl
#define dbv(v) cerr << #v << "="; for (auto _x : v) cerr << _x << ", "; cerr << endl
#define dba(a, n) cerr << #a << "="; for (int _i = 0; _i < (n); ++_i) cerr << a[_i] << ", "; cerr << endl
typedef long long ll;
typedef long double ld;
char S[200005];
void yes() {
	printf("Yes\n");
	exit(0);
}
void no() {
	printf("No\n");
	exit(0);
}
int main() {
	int n, a, b, c, d;
	scanf("%d%d%d%d%d%s", &n, &a, &b, &c, &d, S + 1);
	for (int i = a; i + 1 <= c; ++i)
		if (S[i] == '#' && S[i + 1] == '#') no();
	for (int i = b; i + 1 <= d; ++i)
		if (S[i] == '#' && S[i + 1] == '#') no();
	if (d < c) {
		for (int i = b; i <= d; ++i) {
			if (S[i] != '#' && S[i - 1] != '#' && S[i + 1] != '#') yes();
		}
		no();
	}
	yes();
}
