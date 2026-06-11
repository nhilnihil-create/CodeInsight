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
	int n;
	cin >> n;
	double res = 0;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		res += 1.0 / a;
	}
	cout << setprecision(10) << 1 / res << endl;
}
