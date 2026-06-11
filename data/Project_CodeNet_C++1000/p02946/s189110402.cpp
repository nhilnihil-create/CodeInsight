#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int k, x; cin >> k >> x;
	
	const int leftLimit = -1000000;
	const int rihgtLimit = 1000000;

	int left = max(leftLimit, x - k + 1);
	int right = min(rihgtLimit, x + k - 1);
	
	for (int i = left; i <= right; i++) {
		cout << i << " ";
	}

	cout << endl;
	return 0;
}