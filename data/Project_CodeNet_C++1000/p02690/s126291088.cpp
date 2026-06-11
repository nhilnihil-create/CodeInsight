#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cmath>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int INF = 1001001001;

ll pow_mod(ll x, ll y) {
	ll res = 1;
	rep(i, y) res = res * x % mod;
	return res;
}

int main() {
	ll x;
	cin >> x;
	for (int a = -120; a < 120; a++) {
		for (int b = a - 1000; b < a; b++) {
			if (pow(a, 5) - pow(b, 5) == x) {
				cout << a << " " << b << endl;
				return 0;
			}
		}
	}
	return 0;
}