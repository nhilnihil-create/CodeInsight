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
	int n, k, c;
	string s;
	cin >> n >> k >> c;
	cin >> s;
	vector<int> v1, v2;
	int last = -0x3f3f3f3f;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == 'o' && i - last > c) {
			v1.push_back(i);
			last = i;
		}
	}
	if (v1.size() > k) {
		return 0;
	}
	last = 0x3f3f3f3f;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] == 'o' && last - i > c) {
			v2.push_back(i);
			last = i;
		}
	}
	reverse(v2.begin(), v2.end());
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] == v2[i]) {
			cout << v1[i] + 1 << endl;
		}
	}
}
