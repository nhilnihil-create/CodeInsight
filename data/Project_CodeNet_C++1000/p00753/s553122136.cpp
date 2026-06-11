#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>


using namespace std;

#ifdef _MSC_VER
#define __typeof__ decltype
template <class T> int __builtin_popcount(T n) { return n ? 1 + __builtin_popcount(n & (n - 1)) : 0; }
#endif

#define foreach(it, c) for (__typeof__((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define clear(arr, val) memset(arr, val, sizeof(arr))

#define rep(i, n) for (int i = 0; i < n; ++i)

template <class T> void max_swap(T& a, const T& b) { a = max(a, b); }
template <class T> void min_swap(T& a, const T& b) { a = min(a, b); }

typedef long long ll;
typedef pair<int, int> pint;

const double EPS = 1e-8;
const double PI = acos(-1.0);
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };


const int MAX_PRIME = 123456 * 2;
bool is_prime[MAX_PRIME + 1];
void sieve(int n = MAX_PRIME)
{
	fill_n(is_prime, n + 1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i * i <= n; ++i)
	{
		if (is_prime[i])
		{
			for (int j = 2 * i; j <= n; j += i)
				is_prime[j] = false;
		}
	}
}
int main()
{
	sieve();
	int num[MAX_PRIME + 1];
	num[0] = 0;
	for (int i = 1; i <= MAX_PRIME; ++i)
		num[i] = num[i - 1] + is_prime[i];
	int n;
	while (scanf("%d", &n), n)
		printf("%d\n", num[n * 2] - num[n]);
}