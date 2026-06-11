#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int INF = 1001001001;

ll pow_mod(ll x, ll y) {
	ll res = 1;
	for (ll i = 0; i < y; i++) res = res * x % mod;
	return res;
}

int main() {
	int n;
	cin >> n;
	set<string> s;
	for (int i = 0; i < n; i++) {
		string now;
		cin >> now;
		s.insert(now);
	}
	cout << s.size() << endl;
	return 0;
}