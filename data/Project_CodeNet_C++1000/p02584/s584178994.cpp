#include<bits/stdc++.h>
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;

#define FOR(i,a,b) for (int i = a; i < b; ++i)
#define FORR(i,a,b) for (int i = b - 1; i >= a; --i)
#define REP(i,n) FOR(i,0,n)
#define REPR(i,n) FORR(i,0,n)

ll myabs(ll a) {
	if (a < 0) return -a;
	else return a;
}

int main() {
	ll X, K, D;
	cin >> X >> K >> D;

	if (X >= 0) {
		ll n = X / D + 1;
		if (K < n) {
			cout << myabs(X - D * K) << endl;
		}
		else {
			if (n % 2 == 0) {
				if (K % 2 == 0) cout << myabs(X - D * n) << endl;
				else cout << myabs(X - D * (n - 1)) << endl;
			}
			else {
				if (K % 2 == 0) cout << myabs(X - D * (n - 1)) << endl;
				else cout << myabs(X - D * n) << endl;
			}
		}
	}
	else {
		ll n = -X / D + 1;
		if (K < n) {
			cout << myabs(X + D * K) << endl;
		}
		else {
			if (n % 2 == 0) {
				if (K % 2 == 0) cout << myabs(X + D * n) << endl;
				else cout << myabs(X + D * (n - 1)) << endl;
			}
			else {
				if (K % 2 == 0) cout << myabs(X + D * (n - 1)) << endl;
				else cout << myabs(X + D * n) << endl;
			}
		}
	}

	return 0;
}