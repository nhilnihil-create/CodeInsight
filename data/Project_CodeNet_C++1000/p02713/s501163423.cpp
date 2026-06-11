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
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

int gcd(int p, int q) {
	if (p % q == 0) return q;
	return gcd(q, p % q);
}

int main() {

	int k;
	cin >> k;

	long long ans = 0;
	for (int i = 1;i <= k;i++) {
		for (int j = 1;j <= k;j++) {
			for (int l = 1;l <= k;l++) {
				ans += gcd(gcd(i, j), l);
			}
		}
	}

	cout << ans << endl;

	return 0;
}