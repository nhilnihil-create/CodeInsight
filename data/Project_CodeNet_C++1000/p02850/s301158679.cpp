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

#define rep(i,s,e) for(ll i=s;i<e;i++)
#define repeq(i,s,e) for(ll i=s;i<=e;i++)


int main() {
	ll N;
	std::cin >> N;

	vector<map<ll, ll>> e(N);
	vector<map<ll,bool>> flg(N);
	
	rep(i, 0, N-1) {
		ll a, b;
		std::cin >> a >> b;
		a--; b--;

		e[a][b] = i;
		e[b][a] = i;
	}

	stack<ll> st;
	st.push(0);
	vll col(N - 1,-1);

	ll cnt = 0;
	while (!st.empty()) {
		ll cur = st.top();
		st.pop();
		ll tmp = 1;
		for (auto itr = e[cur].begin(); itr != e[cur].end(); itr++) {
			if (col[itr->second] < 0) {
				while (flg[cur][tmp]) {
					tmp++;
				}
				col[itr->second] = tmp;
				flg[cur][tmp] = true;
				flg[itr->first][tmp] = true;
				st.push(itr->first);
			}
		}
		cnt = max(cnt, tmp);
	}

	std::cout << cnt << endl;
	rep(i, 0, N - 1) {
		std::cout << col[i] << endl;
	}

	return 0;
}
