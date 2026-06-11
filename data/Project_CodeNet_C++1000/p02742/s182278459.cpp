#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int main() {
	long long H, W;
	cin >> H >> W;
	if (H == 1 || W == 1) cout << "1" << endl;
	else cout << (H * W + 1LL) / 2LL << endl;
	return 0;
}