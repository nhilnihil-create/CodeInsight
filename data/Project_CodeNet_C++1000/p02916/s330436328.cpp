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
	vector<int> va(n, 0), vb(n, 0), vc(n - 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> va[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> vb[i];
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> vc[i];
	}
	int res = 0;
	for (int i = 0; i < n; i++) {
		res += vb[i];
		if (i + 1 < n && va[i] + 1 == va[i + 1]) {
			res += vc[va[i] - 1];
		}

	}
	cout << res << endl;
}
