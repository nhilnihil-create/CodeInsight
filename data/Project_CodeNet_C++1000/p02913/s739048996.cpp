#include <iostream>
#include <string>
#include <cstdio>
#include <unordered_map>
#include <vector>
#define task ""
using namespace std;
using ll = long long;
using ld = long double;

const int N = 5e3 + 2;
const ll mod = 1e9 + 7, base = 311;
int n;
ll has[N], Pow[N];
string s;

void Prepare(){
	Pow[0] = 1;
	for(int i = 1; i <= n; ++i){
		Pow[i] = (Pow[i - 1] * base) % mod;
		has[i] = (has[i - 1] * base + (ll)(s[i] - 'a' + 1) ) % mod;
	}
}

void Read(){
	cin >> n >> s;
	s = " " + s;
}

ll cal(int l, int r){
	return (has[r] - has[l - 1] * Pow[r - l + 1] + mod * mod) % mod;
}

bool found(int i, vector<int> &a){
	int l = 0, m, h = a.size() - 1;
	while(l <= h){
		m = (l + h) >> 1;
		if(a[m] < i) l = m + 1;
		else h = m - 1;
	}
	return (l < a.size());
}

bool check(int m){
	unordered_map<ll, vector<int> > cnt;
	for(int i = 1; i <= n - m + 1; ++i){
		cnt[cal(i, i + m - 1)].push_back(i);
	}
	for(auto a : cnt){
		auto &b = a.second;
		for(auto i : b){
			if(found(i + m, b))
				return true;
		}
	}
	return false;
}

void Solve(){
	int l = 1, m, h = n;
	while(l <= h){
		m = (l + h) >> 1;
		if(check(m)) l = m + 1;
		else h = m - 1;
	}
	cout << h;
}

main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
//	freopen(task".INP", "r", stdin);
//	freopen(task".OUT", "w", stdout);
	Read();
	Prepare();
	Solve();
}
