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
#include<functional>
#include<unordered_set>
#include<unordered_map>

using namespace std;
using ll = long long;
using vll = vector<long long>;
using sll = set<long long>;
const long long ll_max = 9223372036854775807;
const long long ll_min = -9223372036854775807;
const int int_max = 2147483647;

template<typename T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T>
T lcm(T a, T b) { return a / gcd(a, b) * b; }

template<typename T>
map<T, T> getPrimeFactor(T n) {
	map<T, T> ret;
	for (T i = 2; i * i <= n; ++i) {
		while (n % i == 0) {
			ret[i] ++;
			n /= i;
		}
	}
	if (n != 1) ret[n] = 1;
	return ret;
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

template<typename T>
T modinv(T a, T m) {
	T b = m, u = 1, v = 0;
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
ll pow2(ll n, ll p, ll mod) {
	if (p == 0 || n == 1) {
		return 1;
	}
	else {
		ll ret = pow2(n * n % mod, p / 2, mod);
		if (p % 2 == 1) {
			ret *= n;
		}
		return ret % mod;
	}
}


#define rep(i,s,e) for(ll i=s;i<e;i++)
#define repeq(i,s,e) for(ll i=s;i<=e;i++)


map<ll, map<ll, ll>> dic;
map<ll, map<ll, ll>> dic3;
map<ll, ll> dic1;
map<ll, ll> dic2;
const ll mod = 1e9 + 7;

ll comb(ll a, ll b) {
	auto itr1 = dic.find(a);
	if (b == 1) {
		return a;
	}
	if (itr1 != dic.end()) {
		auto itr2 = itr1->second.find(b);
		if (itr2 != itr1->second.end()) {
			return itr2->second;
		}
	}
	ll ret = (((dic1[a] * dic2[a - b]) % mod)* dic2[b]) % mod;
	dic[a][b] = ret;
	return ret;
}
ll comb2(ll a, ll b) {
	if (a == b) {
		return 1;
	}
	if (a<b||a==0 || b == 0) {
		return 0;
	}
	else if (b == 1) {
		return 1;
	}
	else {
		return comb(a - 1, b - 1);
	}
}


int main() {
	ll n, k;
	cin >> n >> k;
	dic1[1] = 1;
	dic2[0]=dic2[1] = 1;
	
	repeq(i, 2, n) {
		dic1[i] = (dic1[i - 1] * i) % mod;
		dic2[i] = (dic2[i - 1] * modinv(i, mod)) % mod;
	}

	repeq(i, 1, k) {
		ll l = n - k;
		cout << comb2(k, i) * ((2 * comb2(l, i) % mod) + comb2(l, i + 1) + comb2(l, i - 1)) % mod << endl;
	}

	return 0;
}
