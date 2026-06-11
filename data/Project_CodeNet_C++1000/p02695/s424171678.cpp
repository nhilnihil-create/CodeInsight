#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>
#include <new>
#include <typeinfo>
#include <iterator>

typedef long long ll;
typedef unsigned long long ull;
constexpr ll mop = 1000000007;
constexpr ll mop2 = 998244353;

using namespace std;


ll check(vector<ll> v, vector<vector<ll>>& Qs) {
	ll rev = 0;
	for (ll i = 0; i < Qs.size(); i++) {
		ll a = Qs[i][0] - 1;
		ll b = Qs[i][1] - 1;
		ll c = Qs[i][2];
		ll d = Qs[i][3];
		if (v[b] - v[a] == c) {
			rev += d;
		}
	}
	return rev;

}


int main() {
	ll n,m,Q;
	cin >> n >> m >> Q;
	vector<vector<ll>> Qs(Q);
	for (ll i = 0; i < Q; i++) {
		Qs[i].resize(4);
		cin >> Qs[i][0] >> Qs[i][1] >> Qs[i][2] >> Qs[i][3];
	}
	
	string s;
	for (ll i = 0; i < m - 1; i++) {
		s += '0';
	}
	for (ll i = 0; i < n; i++) {
		s += '1';
	}
	ll ans = 0;
	do {
		vector <ll> v;
		ll now = 1;
		ll j = 0;
		while (j < n + m - 1) {
			if (s[j] == '1') {
				v.push_back(now);
			}
			else {
				now++;
			}
			j++;
		}
		ll tmp = check(v, Qs);
		if (ans < tmp) {
			ans = tmp;
		}

	} while (next_permutation(s.begin(), s.end()));
	cout << ans << endl;
}
