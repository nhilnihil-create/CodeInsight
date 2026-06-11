#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>

typedef long double ld;
typedef long long ll;

using namespace std;

vector<ll> divisors(ll n) {
	vector<ll> ret;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			if (i * i == n) {
				ret.push_back(i);
			} else {
				ret.push_back(i);
				ret.push_back(n / i);
			}
		}
	}
	ret.push_back(n);
	sort(ret.begin(), ret.end());
	return ret;
}

bool sim(ll n, ll k) {
	ll cur = n;
	while (cur >= k) {
		if (cur % k == 0) {
			cur /= k;
		} else {
			cur %= k;
		}
	}
	return (cur == 1);
}

int main() {
	ll n;
	cin >> n;
	vector<ll> divs = divisors(n);
	vector<ll> v1 = divisors(n - 1);
//	vector<ll> v2 = divisors(n + 1);
//	set<ll> s1(v1);
//	set<ll> s2(v2);
//	set<ll> s;
//	merge(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s, s.begin()));

//	for (int i = 0; i < divs.size(); i++) {
		//cout << divs[i] << endl;
//	}

	ll ret = 0;
	for (int i = 0; i < divs.size(); i++) {
		if (sim(n, divs[i])) {
			ret++;
		}
	}
	if (n == 2) {
		cout << "1" << endl;
	} else {
		cout << ret + v1.size() << endl;
	}

	return 0;
}
