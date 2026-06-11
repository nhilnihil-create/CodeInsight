#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps = 1e-9;

map<long long int, int>soinnsuu(long long int a) {
	map<long long int, int>ans;
	for (long long i = 2; i*i <= a; ++i) {
		while (a%i == 0) {
			ans[i]++;
			a /= i;
		}
	}
	if (a != 1)ans[a]++;


	return ans;
}

int main() {
	int N; cin >> N;
	auto mp = soinnsuu(N);
	vector<int>anss;
	for (auto m : mp) {
		for (int i = 0; i < m.second; ++i) {
			anss.emplace_back(m.first);
		}

	}
	cout << N << ":";
	for (auto a : anss) {
		cout << " " << a;
	}
	cout << endl;
	return 0;
}