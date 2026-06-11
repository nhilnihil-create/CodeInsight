#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <array>
#include <deque>
#include <algorithm>
#include <utility>
#include <cstdint>
#include <functional>
#include <iomanip>
#include <numeric>
#include <cassert>
#include <bitset>
#include <list>
#include <cmath>
using namespace std;

int main() {
	int A, B, M;
	cin >> A >> B >> M;
	vector<int> a(A), b(B), x(M), y(M), c(M);
	int amin = 1000000;
	int bmin = 1000000;
	for (int i = 0; i < A; ++i) {
		cin >> a.at(i);
		amin = std::min(amin, a.at(i));
	}
	for (int i = 0; i < B; ++i) {
		cin >> b.at(i);
		bmin = std::min(bmin, b.at(i));
	}
	for (int i = 0; i < M; ++i) {
		cin >> x.at(i) >> y.at(i) >> c.at(i);
	}
	int min = amin + bmin;
	for (int i = 0; i < M; ++i) {
		min = std::min(min, a.at(x.at(i) - 1) + b.at(y.at(i) - 1) - c.at(i));
	}
	cout << min << endl;

	return 0;
}