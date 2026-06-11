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
	char last = ' ';
	int res = 0;
	for (auto ss : s) {
		if (ss != last) res++;
		last = ss;
	}
	cout << res << endl;
}
