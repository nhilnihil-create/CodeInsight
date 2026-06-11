#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cmath>
#include<algorithm>
#include<queue>
#include<set>
#include<stdio.h>
#include<stack>
using namespace std;

int main() {
	int n, m, s;
	cin >> n >> m >> s;
	int limit = 1000000000;
	if (n == m) {
		for (int i = 0; i < n - 1; i++) {
			cout << s << ' ';
		}
		cout << s;
		return 0;
	}
	if (s == limit) {

		for (int i = 0; i < m; i++) {
			cout << limit << ' ';
		}
		for (int i = 0; i < n - m - 1; i++) {
			cout << 1 << ' ';
		}
		cout << 1;
		return 0;
	}
	for (int i = 0; i < m; i++) {
		cout << s << ' ';
	}
	for (int i = 0; i < n - m - 1; i++) {
		cout << limit << ' ';
	}
	cout << limit;
	return 0;
}

