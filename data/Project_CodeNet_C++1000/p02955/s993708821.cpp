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
#include<map>
#include<random>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
#include <queue>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldouble = long double;


//BDD,ZDD,kdtree, bdtree,bicalc, bolonoy, doloney, tree, chinesemod,segmenttree,daikusutora, saidairyuu, 2bugurahu, heirokenshutu, topologicalsort, kyourenketuseibun

#define REP(i,a,b) for(ll i = a; i < b; ++i)
#define PRI(s) cout << s << endl
#define PRIY PRI("Yes")
#define PRIN PRI("No")


vector<pair<long long, int>> factorize(long long n) {
	vector<pair<long long, int>> res;
	for (long long i = 2; i * i <= n; ++i) {
		if (n % i != 0) continue;
		res.emplace_back(i, 0);
		while (n % i == 0) {
			n /= i;
			res.back().second++;
		}
	}
	if (n != 1) res.emplace_back(n, 1);
	return res;
}

vector<ll> A;
ll N, K;
ll ans;
void solve(ll S) {
	if (S == 1)return;
	vector<ll> a,s;
	REP(i, 0, N) if (A[i] % S != 0)a.push_back(A[i] % S);
	sort(a.begin(), a.end());
	s.resize(a.size() + 1);
	s[0] = 0;
	REP(i, 0, a.size())s[i + 1] = s[i] + a[i];
	if (s.back() % S != 0)return;
	REP(i, 1, s.size()) {
		if (s[i] == (a.size() - i)*S - (s.back()-s[i]) && s[i] <= K) {
			ans = max(ans, S);
			return;
		}
	}
}

void f(int ind, vector<pair<ll,int>>& v, ll cur) {
	if (ind == v.size()) {
		solve(cur);
		return;
	}
	ll tmp = 1;
	REP(i, 0, v[ind].second + 1) {
		f(ind + 1, v, cur * tmp);
		tmp *= v[ind].first;
	}
}

int main() {
	cin >> N >> K;
	A.resize(N);
	ll sum = 0;
	ans = 1;
	REP(i, 0, N) {
		cin >> A[i];
		sum += A[i];
	}
	auto v = factorize(sum);
	f(0, v, 1);
	PRI(ans);
	return 0;
}


