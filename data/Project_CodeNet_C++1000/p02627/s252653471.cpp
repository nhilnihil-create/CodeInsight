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

#include <math.h>
using namespace std;
int main() {
	char a;
	cin >> a;
	string big = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	bool b = false;
	for (int i = 0; i < 26; i++) {
		if (big.at(i) == a) {
			b = true;
		}
	}
	if (b) {
		cout << "A" << endl;
	}
	else {
		cout << "a" << endl;
	}
}
