#include <iostream>
using namespace std;

long long solve(long long cur) {
	if(cur == 1)
		return 1;
	return 2 * solve(cur / 2) + 1;
}

int main() {
	long long n;
	cin >> n;
	cout << solve(n);
}
