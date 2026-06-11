#include<bits/stdc++.h>
using namespace std;

int main() {
	long long n, a, b;
	cin >> n >> a >> b;

	if ((b - a) % 2 == 0) {
		cout << (long long)(b - a) / 2 << endl;
	}
	else {
		if (b - a == 1) {
			cout << min(b - 1, n - a) << endl;
		} 
		else {
			cout << (b - a - 1) / 2 + min(a, n - b + 1) << endl;
		}
	}

	return 0;
}
