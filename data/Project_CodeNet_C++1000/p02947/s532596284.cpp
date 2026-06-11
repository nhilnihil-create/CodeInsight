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
	long long int res = 0;
	unordered_map<string, int> um;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		sort(s.begin(), s.end());
		res += um[s];
		um[s]++;
	}
	cout << res << endl;
}
