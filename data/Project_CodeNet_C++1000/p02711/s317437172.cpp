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
	string n;
	cin >> n;
	if (n[0] == '7' || n[1] == '7' || n[2] == '7') cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}