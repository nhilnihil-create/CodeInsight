#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() {
	int n;
	cin >> n;
	int p = n;
	int cnt = 0;
	while (p > 0) {
		cnt++;
		p /= 10;
	}
	if (cnt == 1) {
		cout << n;
		return 0;
	}
	int ans = 9;
	bool e = 0;
	if (cnt % 2 == 1) {
		ans += (n - pow(10,cnt - 1)) + 1;
		//cnt--;
		e = 1;
	}
	//cnt--;
	cnt = (cnt + 1)/ 2;
	cnt--;
	if (e)
		cnt--;
	int z = 900;
	while (cnt--) {
		ans += z;
		z *= 100;
	}
	cout <<ans;
}

















