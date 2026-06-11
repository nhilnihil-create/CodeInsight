#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	int x = 0;
	for (int& ai : a) {
		cin >> ai;
		x ^= ai;
	}

	for (int ai : a) {
		cout << (x ^ ai) << " ";
	}
	
	return 0;
}
