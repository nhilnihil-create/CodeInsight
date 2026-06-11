#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
using namespace std;

int main() {
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> a(q),b(n);

	for (int i = 0; i < q; i++) {
		cin >> a.at(i);
	}
	for (int i = 0; i < n; i++) {
		b.at(i) = 0;
	}
	for (int i = 0; i < q; i++) {
		b.at(a.at(i)-1)++;
	}
	for (int i = 0; i < n; i++) {
		b.at(i) = k - (q  - b.at(i));
	}

	for (int i = 0; i < n; i++) {
		if (b.at(i) > 0)cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;
}