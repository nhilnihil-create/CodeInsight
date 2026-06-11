#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<deque>
#include<array>


#define REP(i,a,b) for(int i = (a); i < b; ++i)
#define inf 1e9+10
#define MOD 1000000007

using ll = long long;
using ull = unsigned long long;
using namespace std;

inline ll modpow(ll x, ll n, ll mod) {
	ll res = 1;
	while (n > 0) {
		if (n & 1) res = res * x % mod;
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

inline ll mod(ll val, ll m) {
	ll res = val % m;
	if (res < 0) res += m;
	return res;
}


int main() {
	int n ,m;
	
	cin >> n >> m;

	vector<pair<int,int>> sc(m);

	REP(i, 0, m) {
		int s, c;
		cin >> s >> c;
		sc[i].first = s;
		sc[i].second = c;
	}

	vector<int> ans(n, -1);

	REP(i, 0, m) {
		if (sc[i].first == 1 && sc[i].second == 0 && n != 1) {
			cout << "-1";
			return 0;
		}
		REP(j, 0, m) {
			if (i != j && sc[i].first == sc[j].first && sc[i].second != sc[j].second) {
				cout << "-1";
				return 0;
			}
			
		}
	}
	REP(i, 0, n) {
		REP(j, 0, m) {
			if (i + 1 == sc[j].first) {
				ans[i] = sc[j].second;
			}
		}
	}
	REP(i, 0, n) {
		if (ans[i] == -1) {
			if (n != 1) {
				if (i == 0) {
					ans[i] = 1;
				}
				else {
					ans[i] = 0;
				}
			}
			else {
				ans[i] = 0;
			}
		}
	}
	REP(i, 0, n) {
		cout << ans[i];
	}
	return 0;
}