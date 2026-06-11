#include <iostream>
#include <iomanip>
#include<math.h>
#include<list>
#include <algorithm>
#include<set>
#include<vector>
#include<math.h>
#include<map>
#include<string>
#include <numeric>
#include <queue>
#include <sstream>
#include <bitset>
#include<stack>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using sll = set<long long>;


template<typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<typename T>
map<T, T> getPrimeFactor(T n) {
	map<T, T> res;
	for (T i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			res[i] ++;
			n /= i;
		}
	}
	if (n != 1) res[n] = 1;
	return res;
}

template<typename T>
bool IsPrimeNumber(T num)
{
	if (num <= 2) return true;
	else if (num % 2 == 0) return false;

	double sqrtNum = sqrt(num);
	for (int i = 3; i <= sqrtNum; i += 2)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}

// 繰り返し二乗法
ll pow2(ll n, ll p) {
	if (p == 0 || n == 1) {
		return 1;
	}
	else {
		ll ret = pow2(n * n, p / 2);
		if (p % 2 == 1) {
			ret *= n;
		}
		return ret;
	}
}

#define rep(i,s,e) for(ll i=s;i<e;i++)
#define repeq(i,s,e) for(ll i=s;i<=e;i++)


int main() {
	ll N;
	std::cin >> N;

	vll A(N);
	rep(i, 0, N) {
		std::cin >> A[i];
	}
	sort(A.begin(), A.end());

	queue<pair<ll, ll>> q;
	// できるだけ大きなマイナスを作っていく
	ll idx_min = 0;
	ll idx_max;
	for (idx_max = N - 1; idx_max > idx_min + 1 && A[idx_max - 1] >= 0; idx_max--) {
		q.push({ A[idx_min],A[idx_max] });
		A[idx_min] -= A[idx_max];
	}

	// 残った非負値にマイナスの数字を引いていく
	while (idx_min < idx_max) {
		q.push({ A[idx_max],A[idx_min] });
		A[idx_max] -= A[idx_min];
		idx_min++;
	}

	// 出力
	std::cout << A[idx_max] << endl;
	while (!q.empty()) {
		std::cout << q.front().first << " " << q.front().second << endl;
		q.pop();
	}

	return 0;
}
