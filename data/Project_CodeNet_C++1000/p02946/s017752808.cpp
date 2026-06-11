#include <bits/stdc++.h>
using namespace std;

int main()
{
	long K, X;
	cin >> K >> X;

	int min = X - (K - 1);
	int max = X + (K - 1);
	for (int loop = min; loop <= max; ++loop) {
		cout << loop << ' ';
	}

	return 0;
}
