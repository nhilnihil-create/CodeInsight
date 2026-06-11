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
	string s, t;
	cin >> s >> t;
	int n = s.size();
	int res = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == t[i]) res++;
	}
	cout << res << endl;
}
