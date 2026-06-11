#pragma once

#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;

#define rep(a,n) for(int a = 0;a < n;a++)
#define repi(a,b,n) for(int a = b;a < n;a++)

int main(void)
{
	ll n;
	cin >> n;
	vector<P> vs(n);
	rep(i, n) {
		int a;
		cin >> a;
		vs[i] = { a, i };
	}
	sort(vs.begin(), vs.end(), std::greater<P>());
	set<ll> upper;
	upper.insert(-1);
	upper.insert(n);
	upper.insert(vs[0].second);
	ll sum = 0;
	for (int i = 1; i < n; i++) {
		auto f = vs[i];
		auto u = upper.upper_bound(f.second);
		if (*u != n) {
			auto w1 = *u;
			u++;
			auto w2 = *u;
			u--;
			u--;
			auto w3 = *u;
			sum += f.first * (w2 - w1) * (f.second - w3);
			if (w3 != -1) {
				u--;
				auto w4 = *u;
				sum += f.first * (w3 - w4) * (w1 - f.second);
			}
		}
		else {
			auto w1 = *u;
			u--;
			auto w3 = *u;
			u--;
			auto w4 = *u;
			sum += f.first * (w3 - w4) * (w1 - f.second);
		}
		upper.insert(f.second);
	}
	cout << sum << endl;
	return 0;
}
