#include <bits/stdc++.h>
using namespace std;

int main() {
	

	int n, k, q,tmp;
	cin >> n >> k >> q;
	vector<int> a(n,0);
	for (int i = 0; i < q; i++) {
		cin >> tmp;
		a.at(tmp - 1)++;
	}
	for (int i:a) {
		if ((k-q+i) <= 0) {
			cout << "No" << endl;
		}
		else {
			cout << "Yes" << endl;
		}
	}
}