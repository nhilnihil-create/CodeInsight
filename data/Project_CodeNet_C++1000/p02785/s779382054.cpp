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
using namespace std;
signed main() {
	int N, K;
	cin >> N >> K;
	int A = 0;

	vector<int>H(N);
	for (int i = 0; i < N; i++) {
		cin >> H[i];
	}
	sort(H.begin(), H.end()); 
	reverse(H.begin(), H.end());
	bool a = true;
	if (K >= N) {
		cout << 0 << endl;
		a = false;
	}
	if (a) {
		for (int i = 0; i < K; i++) {
			H[i] = 0;
		}

		for (int i = 0; i < N; i++) {
			A += H[i];
		}
      cout << A << endl;
	}


}
