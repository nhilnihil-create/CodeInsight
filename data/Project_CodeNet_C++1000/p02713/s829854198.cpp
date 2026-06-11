#include <bits/stdc++.h>
using namespace std;
#define vec(type) vector<type>

int main() {
	int k;
	cin >> k;

	int ans = 0;
	for (int a = 1; a <= k; a++) {
		int bsum = 0;
		for (int b = 1; b <= k; b++) {
			int csum = 0;
			for (int c = 1; c <= k; c++) {
				csum += gcd(gcd(a,b),c);
			}
			bsum += csum;
		}
		ans += bsum;
	}
	cout << ans << endl;
}