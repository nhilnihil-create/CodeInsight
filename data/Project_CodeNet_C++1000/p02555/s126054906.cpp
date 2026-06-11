#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>
#include <cmath>

#define endl '\n'

using namespace std;


void solve() {
	int n;
	cin >> n;
	if (n == 0) {
		cout << "1" << endl;
	} else {
		int arr[n], mod = 1000000007;
		arr[0] = 0; arr[1] = 0; arr[2] = 1;
		for (int i = 3; i < n; i++) {
			arr[i] = (arr[i - 1] + arr[i - 3]) % mod;
		}
		cout << arr[n - 1] << endl;
	}
}

int main() {
	int T = 1;
	//cin >> T;
	while (T--) {
		solve();
	}
	return 0;
}