#include <stdio.h>
#include <vector>
using namespace std;

const long long mod = 1000000007;
long long inv[100100] = { 0,1 }, fact[100100] = { 1,1 }, ifact[100100] = { 1,1 };
long long comb(int n, int k)
{
	if (n < 0 || k < 0 || k > n) return 0;
	return fact[n] * ifact[n - k] % mod;
}

int n, k;
vector<int> g[100100];

long long count(int x, int l)
{
	long long r = 1;

	int c = 0;
	for (auto &y : g[x]) if (y != l){
		r = r * count(y, x) % mod; c++;
	}
	r = r * comb(k - 1 - (l > 0), c) % mod;
	
	return r;
}

int main()
{
	for (int i = 2; i < 100100; i++){
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
		fact[i] = fact[i - 1] * i % mod;
		ifact[i] = ifact[i - 1] * inv[i] % mod;
	}

	scanf ("%d %d", &n, &k);
	for (int i = 1; i < n; i++){
		int x, y; scanf ("%d %d", &x, &y);
		g[x].push_back(y);
		g[y].push_back(x);
	}

	printf ("%lld\n", count(1, 0) * k % mod);

	return 0;
}
