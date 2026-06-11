#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;

int main() {
	int n;
	int m = 0;
	int maxi;
	cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a.at(i);
		b.at(i) = a.at(i);
		if (m < a.at(i)) {
			m = a.at(i);
			maxi = i;
		}
	}
	sort(b.begin(), b.end(), greater<>());
	for (int i = 0; i < n; i++) {
		if (i != maxi)cout << m << endl;
		else if (i == maxi)cout << b.at(1) << endl;
	}

	return 0;

	
}