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
	long long int x;
	cin >> x;
	unordered_map<long long int, int> um;
	for (long long int i = 0; i <= 1000; i++) {
		um[i * i * i * i * i] = i;
		um[-i * i * i * i * i] = -i;
	}
	for (auto p : um) {
		long long int n = p.first;
		if (um.find(n - x) != um.end()) {
			cout << p.second << " " << um[n - x] << endl;
			return 0;
		}
		if (um.find(n + x) != um.end()) {
			cout << um[n + x] << " " << p.second << endl;
			return 0;
		}
	}
}
