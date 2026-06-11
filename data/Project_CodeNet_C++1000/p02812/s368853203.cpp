#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
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
	string s;
	cin >> n >> s;
	int ans = 0;
	for (int i = 0; i < n - 2; i++) {
		if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') ans++;
	}
	cout << ans << endl;
	return 0;
}