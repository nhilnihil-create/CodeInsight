#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<functional>
#include<string>
#include<cstring>
#include<time.h>
#include<array>
#include<iomanip>
#include<list>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<bitset>
#include <queue>
#include <map>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldouble = long double;


//BDD,ZDD,kdtree, bdtree,bicalc, bolonoy, doloney, tree, chinesemod,segmenttree,daikusutora, saidairyuu, 2bugurahu, heirokenshutu, topologicalsort, kyourenketuseibun

#define REP(i,a,b) for(int i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIY PRI("Yes")
#define PRIN PRI("No")



int ctoi(char c) {
	switch (c)
	{
	case '0': return 0;
	case '1': return 1;
	case '2': return 2;
	case '3': return 3;
	case '4': return 4;
	case '5': return 5;
	case '6': return 6;
	case '7': return 7;
	case '8': return 8;
	case '9': return 9;
	default:
		std::cout << "ERR_ctoi" << std::endl;
		return -1;
	}
}
long long inverse(long long mod, long long val) {
	long long x[2] = { mod, val };
	long long a[2] = { 1, 0 };
	long long i;
	for (i = 0; x[!i]; i ^= 1) {
		a[!i] -= x[i] / x[!i] * a[i];
		x[i] = x[i] % x[!i];
	}
	if (!i) a[!i] += mod;
	return a[!i];
}


int main() {
	vector<ll> T;
	string str;
	ll N, P;
	cin >> N >> P;
	cin >> str;
	if (P == 2 || P == 5) {
		ll sum = 0;
		for (int i = N - 1; i >= 0; --i) if (ctoi(str[i]) % P == 0) sum += i + 1;
		PRI(sum);
		return 0;
	}
	T.resize(P, 0);
	ll c0 = ctoi(str[0]) % P;
	++T[c0];
	ll ans = T[0];
	ll inv10 = inverse(P, 10);
	ll inv10i = 1;
	ll s_sum = 0;
	auto p = [&](ll x) {return inv10i * (P + x - s_sum) % P; };
	REP(i, 1, N) {
		int ci = ctoi(str[i]) % P;
		s_sum = (10 * s_sum + ci) % P;
		inv10i = inv10i * inv10 % P;
		++T[p(ci)];
		ans += T[p(0)];
	}
	PRI(ans);
	return 0;
}


