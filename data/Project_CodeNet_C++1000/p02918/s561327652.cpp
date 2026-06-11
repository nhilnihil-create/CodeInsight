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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	int c = 1;
	char last = s[0];
	for (int i = 1; i < n; i++) {
		if (last != s[i]) c++;
		last = s[i];
	}
	c = max(1, c - 2 * k);
	cout << n - c << endl;
}
