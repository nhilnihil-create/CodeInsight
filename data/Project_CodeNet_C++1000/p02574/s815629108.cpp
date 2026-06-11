#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265358979323846
#define mod 1000000007
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define pb push_back
#define all(c) (c).begin(), (c).end()

const int N = 1e6;

int n, a[N], spf[N + 1], g;
bool vis[N + 1];

int gcd(int a, int b) {
	if (b == 0)
		return a;

	return gcd(b, a % b);
}

void sieve(int lim = N) {
	for (int i = 2; i <= lim; ++i) {
		if (spf[i] == 0) {
			for (int j = i; j <= lim; j += i)
				spf[j] = i;
		}
	}
}

vi factorize(int x) {
	vi ret;
	while (x != 1) {
		ret.pb(spf[x]);

		x /= spf[x];
	}

	return ret;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	cin >> n;
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);

	for (int i = 0; i < n; ++i)
		g = gcd(g, a[i]);
	
	if (g != 1)
		return puts("not coprime"), 0;

	sieve();
	vi v;
	for (int i = 0; i < n; ++i) {
		v = factorize(a[i]);

		for (int x : v)
			if (vis[x])
				return puts("setwise coprime"), 0;

		for (int x : v)
			vis[x] = 1;
	}

	puts("pairwise coprime");
}
