#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	LL n;
	cin >> n;
	if (n % 2 == 1) {
		cout << "0\n";
	} else {
		LL answer = 0;
		LL p = 1;
		while (n / (10 * p) != 0) {
			answer += n / (10 * p);
			p *= 5;
		}
		cout << answer << '\n';
	}
	return 0;
}
