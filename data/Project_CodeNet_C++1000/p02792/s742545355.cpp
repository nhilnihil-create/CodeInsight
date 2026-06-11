#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	long long n;
	cin >> n;
	map<int, long long> m;
	for (long long i = 1; i <= n; i++) {
		if (i <= 9) {
			m[i*10+i]++;
		} else if (i <= 99) {
			m[i]++;
		} else if (i <= 999) {
			m[(i/100)*10 + i%10]++;
		} else if (i <= 9999) {
			m[(i/1000)*10 + i%10]++;
		} else if (i <= 99999) {
			m[(i/10000)*10 + i%10]++;
		} else if (i <= 999999) {
			m[(i/100000)*10 + i%10]++;
		}
	}
	long long ans = 0;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			ans += m[i*10+j]*m[j*10+i];
		}
	}
	cout << ans << endl;
	return 0;
}