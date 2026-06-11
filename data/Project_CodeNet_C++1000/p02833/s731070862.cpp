#include <bits/stdc++.h>

using namespace std;

int main() {

	long long n;
	cin >> n;

	long long res = 0;
	if (n % 2 == 0) {
		long long tenth = 5;
		long long counter = 0;
		while (tenth <= n) {

			res += n / (long long)pow(5,counter)/10;
			tenth *= 5;
			counter++;
		}
	}

	cout << res << endl;

	return 0;
}