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
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;

	string ans;
	ans.clear();

	for (int i = 0;i < n;i++) {
		ans += s[i];
		ans += t[i];
	}

	cout << ans << endl;

	return 0;
}