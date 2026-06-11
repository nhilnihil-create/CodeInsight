#include<bits/stdc++.h>
using namespace std;
int main () {
	int n;
	cin >> n;
	int x1 = floor(n/1.08);
	int x2 = ceil(n/1.08);
	if ((int)(x1*1.08)==n) {
		cout << x1; return 0;
	}
	if ((int)(x2*1.08)==n) {
		cout << x2; return 0;
	}
	cout << ":(";
	return 0;
} 