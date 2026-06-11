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
	bool X = false;
	vector<int>A(9);
	vector<bool>ans(9, false);
	for (int i = 0; i < 9; i++) {
		cin >> A[i];
	}
	int N;
	cin >> N;
	vector<int>b(N);
	for (int i = 0; i < N; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 9; j++) {
			if (A[j] == b[i]) {
				ans[j] = true;
			}
		}
	}
	
		if (ans[0] == ans[1] && ans[2] == ans[0] && ans[0]==true) {
			X = true;
		}
		if (ans[3] == ans[4] && ans[4] == ans[5] && ans[3] == true) {
			X = true;
		}
		if (ans[6] == ans[7] && ans[7] == ans[8] && ans[6] == true) {
			X = true;
		}
		if (ans[0] == ans[3] && ans[3] == ans[6] && ans[6] == true) {
			X = true;
		}
		if (ans[1] == ans[4] && ans[4] == ans[7] && ans[7] == true) {
			X = true;
		}
		if (ans[2] == ans[5] && ans[2] == ans[8] && ans[8] == true) {
			X = true;
		}
		if (ans[0] == ans[4] && ans[4] == ans[8] && ans[8] == true) {
			X = true;
		}
		if (ans[2] == ans[4] && ans[4] == ans[6] && ans[6] == true) {
			X = true;
		}
		
	
	if (X == true) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

}