#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <numeric>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <stack>
#include <deque>
#include <bitset>
using namespace std;

#define rep(i, n) for (int i=0; i<int(n); i++)
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
using ll = long long;


int main() {
	int n;
	cin >> n;
	int B[n+1];
	B[0] = 1000000;
	B[n] = 1000000;
	for (int i=1; i<n; i++) {
		cin >> B[i];
	}
	int res = 0;
	rep(i, n) {
		res += min(B[i], B[i+1]);
	}
	cout << res << endl;
}