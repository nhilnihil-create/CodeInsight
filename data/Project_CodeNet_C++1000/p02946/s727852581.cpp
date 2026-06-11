#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	int k, x;
	cin >> k >> x;
	int n = 1000000;
	for (int i = max(-n, x - k + 1); i <= min(n, x + k - 1); i++) {
		cout << i << " ";
	}
	cout << endl;
}
