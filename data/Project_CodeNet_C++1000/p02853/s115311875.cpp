#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cstring>
using namespace std;

const long long mod = pow(10, 9) + 7;

int main() {
	int X, Y,ans=0;
	cin >> X >> Y;
	if (X == 3 || Y == 3) {
		ans += 100000;
		if (X == Y)ans *= 2;
	}
	if (X == 2 || Y == 2) {
		ans += 200000;
		if (X == Y)ans *= 2;
	}
	if (X == 1 || Y == 1) {
		ans += 300000;
		if (X == Y) {
			ans *= 2;
			ans += 400000;
		}
	}
	cout << ans << endl;
}



