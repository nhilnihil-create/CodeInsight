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
	string s;
	cin >> s;
	int res = 0;
	for (int i = 1; i < n; i++) {
		int c = 0;
		for (int j = 0; j + i < n; j++) {
			if (s[j] == s[j + i]) {
				c++;
				res = max(res, min(c, i));
			} else {
				c = 0;
			}
		}
	}
	cout << res << endl;
}
