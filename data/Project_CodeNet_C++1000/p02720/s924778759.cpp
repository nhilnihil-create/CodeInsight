#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef vector<int> vi;

void swap(int a,int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

ll runrun(ll a) {
	queue<ll> Q;
	for (ll i = 1; i < 10;i++) {
		Q.push(i);
	}

	ll count = 1;

	while (1) {
		ll x = Q.front();
		Q.pop();

		if (a==count) {
			return x;
		}
		else {
			if (x % 10 != 0) {
				Q.push(x * 10 + (x % 10 -1));
			}

			Q.push(x * 10 + (x % 10));

			if (x % 10 != 9) {
				Q.push(x * 10 + (x % 10 + 1));
			}
		}

		count++;
	}
}

int main(void) {
	ll k;
	cin >> k;

	cout << runrun(k) << endl;

	return 0;
}