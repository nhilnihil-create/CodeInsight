#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int k;
	cin >> k;
	long long tot = 0;
	for(int i = 1; i <= k; ++i)
		for(int j = 1; j <= k; ++j)
			for(int p = 1; p <= k; ++p)
				tot += __gcd(i, __gcd(j, p));
	cout << tot;
}
