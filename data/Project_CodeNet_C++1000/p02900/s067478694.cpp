#include <bits/stdc++.h>

using namespace std;

map< long long, int > prime_factor(long long n) {
	map< long long, int > ret;
	for (long long i = 2; i * i <= n; i++) {
		while (n % i == 0) {
			ret[i]++;
			n /= i;
		}
	}
	if (n != 1) ret[n] = 1;
	return ret;
}

int main() {

	long long x;
	map<long long, int > a;
	cin >> x;
	a = prime_factor(x);
	a.insert(make_pair(1, 1));
//	a.insert(make_pair(x, 1));
	auto iter = a.begin();

	vector<long long> acount;

	while (iter != a.end()) {
		acount.push_back(iter->first);
		iter = next(iter, 1);
	}

	map<long long, int > b;
	cin >> x;
	b = prime_factor(x);
	b.insert(make_pair(1, 1));
//	b.insert(make_pair(x, 1));
	auto itr = b.begin();

	vector<long long> bcount;

	while (itr != b.end()) {
		bcount.push_back(itr->first);
		itr = next(itr, 1);
	}

	long long res = 0;
	for (int i = 0; i < acount.size(); i++) {
		for (int j = 0; j < bcount.size(); j++) {
			if (acount[i] == bcount[j]) {
				res++;
			}
		}
	}
	cout << res << endl;
}