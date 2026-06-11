#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

struct Combination
{
	vector<ll> fact, inv, invFact;
	int MAX_FACT;
	ll MOD;
	Combination(int n, ll mod) : fact(n + 1), inv(n + 1), invFact(n + 1)
	{
		MAX_FACT = n + 1;
		MOD = mod;
		fact[0] = 1;
		fact[1] = 1;
		invFact[0] = 1;
		invFact[1] = 1;
		inv[1] = 1;
		for (auto i = 2; i < MAX_FACT; ++i)
		{
			fact[i] = fact[i - 1] * i % MOD;
			inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
			invFact[i] = invFact[i - 1] * inv[i] % MOD;
		}
	}

	unsigned long long calcCombination(int n, int k)
	{
		if (n < k)
		{
			return 0;
		}
		if ((n < 0) || (k < 0))
		{
			return 0;
		}

		return fact[n] * (invFact[k] * invFact[n - k] % MOD) % MOD;
	}
};

int main()
{
	int N, K;
	cin >> N >> K;

	auto mod = (ll)1e9 + 7;
	Combination c(N + 1, mod);

	for (auto i = 1; i <= K; ++i)
	{
		auto ans = c.calcCombination(K - 1, i - 1) * c.calcCombination(N - K + 1, i) % mod;
		cout << ans << endl;
	}

	return 0;
}