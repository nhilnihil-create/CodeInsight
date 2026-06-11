#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 1000000007
#define TE 2e5
using namespace std;
using ll = long long;
using ldb = long double;


int gcd(int p, int q) {
	int upper, lower, r;

	if (p >= q) upper = p, lower = q;
	else upper = q, lower = p;
	r = upper % lower;
	if (r)return gcd(lower, r);
	else return lower;
}

int main() {
	ll N, M; cin >> N >> M;
	vector<ll> a(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	ll ans = 0;
	ll sd = 0, p = 1, temp = a[0];
	while (temp % 2 == 0) { temp /= 2, sd++; }
	for (int i = 0; i < N ; i++) {
		ll cnt = 0, temp = a[i];
		while (temp % 2 == 0) {
			temp /= 2;
			cnt++;
		}

		if (sd != cnt) {
			p = M + 1;
			break;
		}
		p = p * (a[i] / 2) / gcd(p, a[i] / 2);
		//cout << "gcd=" << gcd(p, a[i] / 2) << endl;
		//cout << "p=" << p << endl;
		
		
	}

	ans = (M / p + 1) / 2;
	cout << ans << endl;
}
