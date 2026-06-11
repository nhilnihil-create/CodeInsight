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
	long long n, a, b;
	cin >> n >> a >> b;
	long long ans = 0;
	long long tmp = a * (n / (a + b));
	if (n % (a + b) < a) {
		ans = tmp + n % (a + b);
	}
	else ans = tmp + a;

	cout << ans << endl;

	return 0;
}
