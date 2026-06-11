#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>

using namespace std;

int main() {
	int n;
	char s[100];

	cin >> n;
	cin >> s;
	int ans = 0;

	for (int i = 0; i < n - 2; ++i) {
		if (s[i] == 'A' && s[i + 1] == 'B' && s[i + 2] == 'C') {
			ans += 1;
		}
	}
	cout << ans << endl;

}

