#include "bits/stdc++.h"

using namespace std;



int main() {
	int N ;
	cin >> N;
	long long ans = 0;
	for (int n = 0; n <= N;++n) {
		if (0 == n%3) {
			continue;
		}
		if (0 == n%5) {
			continue;
		}
		ans += (long long)n;
	}
	cout << ans <<endl;
	return 0;
}