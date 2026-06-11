#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <map>
#include <queue>
#define rep(i,n) for (int i=0;i<(n);i++)

using namespace std;

int main() {
	string s;
	cin >> s;

	string r_s = s;
	reverse(r_s.begin(), r_s.end());

	int ans = 0;
	for (int i = 0;i < s.length() / 2;i++) {
		if (s[i] != r_s[i]) {
			ans++;
		}
	}

	cout << ans << endl;

	return 0;
}