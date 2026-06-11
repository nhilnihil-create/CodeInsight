#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <string>
#include <array>
#include <cmath>
#include <queue>
#include <stack>
#include <numeric>

using namespace std;


int main() {
	double n,cnt=0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			cnt++;
		}
	}
	double ans = cnt / n;

	cout << ans;
}