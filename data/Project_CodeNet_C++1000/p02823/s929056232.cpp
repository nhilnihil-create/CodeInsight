#include <bits/stdc++.h>

using namespace std;

int main() {

	long long n, a, b;
	cin >> n >> a >> b;

	if ((b-a) % 2 == 0){
		cout << (b - a) / 2 << endl;
	}
	else {

		long long counter=0;
		if (a - 1 < n - b) {
			counter += a - 1 + 1 + (b - (a - 1) - 1-1) / 2;
			cout << counter << endl;
		}
		else {
			counter += n - b + 1 + (n - (a + (n - b) + 1)) / 2;
			cout << counter << endl;
		}
	}


	return 0;
}