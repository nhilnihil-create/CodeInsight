#include"bits/stdc++.h"
#include<iostream>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
#define rep(i, c) for(int i = 0; i < (int)c; i++)
const ll inf = 1000000007;

int main() {
	int n;
	cin >> n;
	map<string, int> m;
	rep(i, n) {
		string a;
		cin >> a;
		m[a] += 1;
	}

	int max_c = 0;
	for (auto itr = m.begin(); itr != m.end(); itr++) {
		max_c = max(max_c, itr->second);
	}

	for (auto itr = m.begin(); itr != m.end(); itr++) {
		if (max_c== itr->second) {
			cout << itr->first << endl;
		}
	}
	return 0;
}