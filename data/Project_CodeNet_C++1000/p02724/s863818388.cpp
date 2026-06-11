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

int main() {
	int x;
	cin >> x;
	long long _500 = x / 500;
	long long _5 = x % 500 / 5;
	long long ans = _500 * 1000 + _5 * 5;

	cout << ans << endl;
	return 0;
}