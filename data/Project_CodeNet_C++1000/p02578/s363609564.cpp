#include <iostream>
#include <bitset>
#include <math.h>
#include <algorithm>
#include <vector>;
#include <numeric>
using namespace std;

int main() {
		
	int n;
	cin >> n;

	long long ans = 0, a, c = 0;;
	for (int i = 0;i < n;i++) {
		cin >> a;
		if (a < c) {
			ans += c - a;
		}
		if (a > c) c = a;
	}

	cout << ans << endl;


	return 0;
}