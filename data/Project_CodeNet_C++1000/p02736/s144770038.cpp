
// Problem : B - 123 Triangle
// Contest : AtCoder - AtCoder Grand Contest 043
// URL : https://atcoder.jp/contests/agc043/tasks/agc043_b
// Memory Limit : 1024 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>
using namespace std;

void doOnce(const vector<int>& a, vector<int>& v) {
	for (int i = 0; i < a.size() - 1; i++) {
		v[i] = abs(a[i] - a[i + 1]);
	}
}

void computeTwos(vector<int>& twos) {
	int n = twos.size();
	for (int i = 2; i < n; i *= 2) {
		for (int j = i; j < n; j += i) {
			twos[j]++;
		}
	}
	for (int i = 1; i < n; i++) {
		twos[i] += twos[i - 1];
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	cin >> N;
	string s;
	cin >> s;
	vector<int> a(N);
	for (int i = 0; i < N; i++) {
		a[i] = s[i] - '0';
	}
	vector<int> v(N - 1);
	doOnce(a, v);
	
	vector<int> twos(N + 1);
	computeTwos(twos);
	
	auto chooseOdd = [&](int n) {
		return twos[N - 2] - twos[n] - twos[N - 2 - n] == 0;
	};
	
	auto getXored = [&](int d) {
		int xored = 0;
		for (int i = 0; i < N - 1; i++) {
			if (chooseOdd(i)) {
				xored ^= v[i]/d;
			} else {
				xored ^= 0;
			}
		}
		return xored;
	};
	
	if (getXored(1) & 1) {
		cout << "1\n";
		return 0;
	}
	
	for (int i = 0; i < N - 1; i++) {
		if (v[i] == 1) {
			cout << "0\n";
			return 0;
		}
	}
	
	if (getXored(2) & 1) {
		cout << "2\n";
	} else {
		cout << "0\n";
	}
}
























