#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <climits>
#include <iomanip>

using namespace std;

int main() {
	int n, k;
	int p,q;
	cin >> n >> k;

	vector<int> arr(n+1);

	for (int i = 0; i < k; i++) {
		cin >> p;
		for (int j = 0; j < p; j++) {
			cin >> q;
			arr[q]++;
		}
	}

	int ans = 0;
	for (int i = 1 ; i <= n; i++) {
		if (arr[i] == 0)ans++;
	}

	cout << ans << endl;

	return 0;
}