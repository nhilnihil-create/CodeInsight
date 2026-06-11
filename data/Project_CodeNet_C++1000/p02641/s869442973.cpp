#include "bits/stdc++.h"
using namespace std;

#define ll long long
#define rep(i,n) for(int i = 0;i < (n); i++)

int main() {
	int x, n;
	int i, j;
	int buf;
	cin >> x >> n;
	int a[201] = { 0 };
	int ans;
	rep(i, n) {
		cin >> buf;
		a[buf]++;
	}
	for (i = 0; i <= 100; i++) {
		if (x - i >= 0) {
			if (a[x - i] == 0) {
				ans = x - i;
				break;
			}
		}
		else {
			ans = x - i;
			break;
		}
			
			if (a[x + i] == 0) {
				ans = x + i;
				break;
			}
	}
	cout << ans << endl;

	return 0;
}
