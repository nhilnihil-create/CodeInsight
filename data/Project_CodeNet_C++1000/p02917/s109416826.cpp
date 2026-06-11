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
using namespace std;
using ll = long long;
using vl = vector<long long>;
using vs = vector<string>;
using ii = vector<vector<long long>>;
int main() {
	ll a;
	cin >> a;
	vl x(a - 1);
	vl y(a);
	for (int i = 0; i < a - 1; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < a-1; i++) {
		if (i != 0) {
			y[i] = min(x[i], x[i - 1]);
		}
		else {
			y[i] = x[i];
		}
	}
	ll count = 0;
	for (int i = 0; i < a; i++) {
		count += y[i];
	}
	cout << count+x[a-2] << endl;
}