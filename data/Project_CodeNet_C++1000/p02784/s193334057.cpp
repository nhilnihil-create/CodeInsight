#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#define int long long
#define double long long
using namespace std;
signed main() {
	int H, N;
	cin >> H >> N;
	int ans = 0;
	bool X = false;

	vector<int>A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		ans += A[i];
		if (ans >= H) {
			X = true;
		}
	}
	if (X == true) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}