#include <bits/stdc++.h>
#define X first
#define Y second

using namespace std;
typedef long long llint;

const int maxn = 3e5+10;
const int base = 31337;
const llint mod = 1e9+7;
const int inf = 0x3f3f3f3f;
const int logo = 18;
const int off = 1 << logo;
const int treesiz = off << 1;

int n;
llint niz[maxn];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%lld", niz+i);
		
	llint sol = 0;
	for (int i = 0; i < 61; i++) {
		llint a = 0, b = 0;
		for (int j = 0; j < n; j++) {
			if (niz[j] & (1LL << i)) a++;
			else b++;
		}
		//printf("debug %d -> %lld %lld\n", i, a, b);
		llint tren = a * b;
		tren %= mod;
		tren *= (1LL << i) % mod; tren %= mod;
		sol += tren;
		sol %= mod;
	}
	printf("%lld", sol);
	return 0;
}

