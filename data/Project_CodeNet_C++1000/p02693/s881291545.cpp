#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF 10000000000
#define PI 3.141592653589793

int main() {
	int k, a, b;
	string ans = "NG";
	cin >> k >> a >> b;

	for (int i = a; i < b + 1; i++) {
		if (i%k == 0) {
			ans = "OK";
			break;
		}
	}

	cout << ans;
	return 0;
}