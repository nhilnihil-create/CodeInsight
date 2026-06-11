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
	int n, d;
	cin >> n >> d;
	d = d * 2 + 1;
	cout << n / d + (n % d > 0 ? 1 : 0) << endl;
}
