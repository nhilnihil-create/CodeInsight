#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	long long n;
	cin >> n;
	if (n%2 == 1) {
		cout << 0 << endl;
		return 0;
	}
	long long count2 = 0;
	long long tmp2 = 1;
	for (int i = 1; ; i++) {
		tmp2 *= 2;
		if (tmp2 > n)
			break;
		long long m = n/tmp2;
		if (m%2 == 0)
			m -= 1;
		count2 += i*((m - 1)/2+1);
	}

	long long count5 = 0;
	long long tmp5 = 1;
	for (int i = 1; ; i++) {
		tmp5 *= 5;
		if (tmp5 > n)
			break;
		long long m = n/(tmp5*2);

		int mod = m%5;
		if (mod == 0) {
			count5 += i*m/5*4;
		} else if (mod == 1) {
			count5 += i*((m-1)/5 * 4 + 1);
		} else if (mod == 2) {
			count5 += i*((m-2)/5 * 4 + 2);
		} else if (mod == 3) {
			count5 += i*((m-3)/5 * 4 + 3);
		} else if (mod == 4) {
			count5 += i*((m-4)/5 * 4 + 4);
		}
		//printf("tmp5: %lld, count5: %lld\n", tmp5, count5);

	}
	//printf("2:%lld, 5:%lld\n", count2, count5);
	cout << min(count2, count5) << endl;
	return 0;
}