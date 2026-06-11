#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	long long n;
	cin >> n;
	long long min = -1;
	for (long long i = 1; i*i <= n; i++) {
		if (n%i != 0)
			continue;
		long long a = n/i;
		long long tmp = (i-1)+(a-1);
		if (min == -1)
			min = tmp;
		else {
			if (tmp < min)
				min = tmp;
		}
	}
	cout << min << endl;
	return 0;
}