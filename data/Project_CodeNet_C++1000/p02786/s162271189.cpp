#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
using ll = long long;


ll fn(ll H) {
	if (H == 1) return 1;
	else return 1 + 2 * fn(H/2);
}

int main() {
	ll H;
	cin >> H;
	cout << fn(H) << endl;
}