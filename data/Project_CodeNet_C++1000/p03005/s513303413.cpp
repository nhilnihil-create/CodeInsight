#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int n, k;
	cin >> n >> k;
	if (k != 1)
		n -= k;
	else
		n = 0;
	cout << n << endl;
	return 0;
}
