/*
                ******
		
        Author: Nguyen Phuc Chuong

                ******
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		int t = n / i;
		if (n % i == 0) {
			t--;
		}
		ans += t;
	}
	cout << ans;
	return 0;
}
