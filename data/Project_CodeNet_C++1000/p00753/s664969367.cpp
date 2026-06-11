
#include "bits/stdc++.h"
using namespace std;


bool isso(long long int a) {
	if (a == 1 || a == 0)return false;
	for (long long int i = 2; i*i <= a; ++i) {
		if ((a%i)) {
		}
		else {
			return false;
		}
	}
	return true;
}
int main() {
	while (1) {
		int n; cin >> n;
		int a = 0;
		if (!n)break;
		for (int i = n + 1; i <= 2 * n; ++i) {
			if (isso(i))a++;
		}
		cout << a << endl;
	}
	return 0;
}