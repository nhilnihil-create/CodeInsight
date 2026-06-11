#include<iostream>
#include<vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using P = pair<int, int>;
#include<algorithm>
#include<math.h>
#include<map>
#include<queue>
#include<set>

set<ll>s;
ll ans(0);
//素因数分解　
//pair<ll,ll>型
//auto pf=prime_factorize(ll N);で呼ぶ
//for(auto p:pf){}で探す

vector<pair<ll, ll>>prime_factorize(ll n) {
	vector<pair<ll, ll>>res;
	for (ll p = 2; p * p <= n; ++p) {
		if (n % p != 0)continue;
		int num = 0;
		while (n % p == 0) {
			++num;
			n /= p;
		}
		res.push_back(make_pair(p, num));
		if (s.count(p))ans++;
		else s.insert(p);
	}
	if (n != 1) {
		res.push_back(make_pair(n, 1));
		if (s.count(n))ans++;
		else s.insert(n);
	}
	return res;
}

int main() {
	ll x, y;
	cin >> x >> y;
	
	auto pf=prime_factorize(x);
	auto pf2=prime_factorize(y);
	cout << ans + 1;
	return 0;
}